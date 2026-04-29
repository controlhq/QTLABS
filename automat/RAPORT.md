

1. Aktualizacja wyświetlanego czasu

Czas jest odświeżany co sekundę przez mechanizm QTimer + slot updateDataTime().

basewindow.cpp


// basewindow.h — pole klasy
QTimer timer;

// basewindow.cpp — konstruktor 
connect(&timer, &QTimer::timeout, this, &BaseWindow::updateDataTime);
timer.setInterval(1000);   // co 1000 ms = 1 sekunda
timer.start();



// basewindow.cpp — slot 
void BaseWindow::updateDataTime() {
    QDateTime now = QDateTime::currentDateTime();
    ui->dateTime->setText(now.toString("yyyy-MM-dd hh:mm:ss"));
}


co sekundę QTimer emituje sygnał timeout, który wywołuje slot updateDataTime(). Slot pobiera bieżącą datę i godzinę z systemu i wstawia sformatowany tekst do etykiety dateTime.


Analogiczny mechanizm istnieje w oknie płatności.


2. Użycie "Promote to"/Zastąp w qtDesignerze



Funkcja Promote to/Zastąp przez w Qt Designer pozwala podmienić standardowy widget Qt (np. QWidget) na własną klasę pochodną napisaną w C++. W pliku .ui zostaje zapisana informacja o klasie bazowej, nazwie klasy docelowej i pliku nagłówkowym — Qt generuje kod, który tworzy obiekt właściwej klasy w miejsce placeholdera.



Dzięki temu ui->payment jest w kodzie C++ od razu wskaźnikiem na PaymentWindows*, a nie na QWidget*. Można więc wprost wywoływać metody specyficzne dla tej klasy, np.:


// appbase.cpp 
ui->payment->setAmountToPay(amount, normal, reduced);

// appbase.cpp
ui->summary->displaySummary(change, normal, reduced);




3. Kawałek kodu odpowiedzialny za pojawianie się i chowanie okienka z "monetami"

CoinInserter jest osobnym oknem (osobnym QWidget bez rodzica w hierarchii layoutu), które pojawia się i znika razem z oknem płatności.

Deklaracja w klasie PaymentWindows 


CoinInserter coinInserter;   


pokazywanie - `showEvent` 


void PaymentWindows::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);   // wywołanie bazowej implementacji
    coinInserter.show();         // pokazuje okienko z przyciskami monet
}


showEvent jest wywoływany automatycznie przez Qt za każdym razem, gdy PaymentWindows staje się widoczne (np. przez stackedWidget->setCurrentWidget(ui->payment)).

Chowanie — hideEvent 


void PaymentWindows::hideEvent(QHideEvent *event)
{
    QWidget::hideEvent(event);   // wywołanie bazowej implementacji
    coinInserter.hide();         // chowa okienko z przyciskami monet
}


hideEvent jest wywoływany automatychmicznie gdy PaymentWindows przestaje być aktywną stroną QStackedWidget, np. po udanej płatności lub po kliknięciu "Powrót".


4. Widok podsumowania — powrót do ekranu głównego po 10 sekundach

Krok 1 — uruchomienie jednorazowego timera 


void summaryWindow::displaySummary(int change, int normal, int reduced) {
    ui->label_normaltickets->setText(QString::number(normal));
    ui->label_discounttickets->setText(QString::number(reduced));
    ui->label_change->setText(QString("%1,%2 zł").arg(change/100).arg(change%100, 2, 10, QChar('0')));

    QTimer::singleShot(10000, this, [this]() {
        emit finished();       // emitowany dokładnie raz, po 10 sekundach
    });
}


QTimer::singleShot(10000, ...) uruchamia jednorazowy timer na 10 sekund. Po upływie czasu lamda emituje sygnał finished().

Krok 2 — reakcja w AppBase 


connect(ui->summary, &summaryWindow::finished, this, [this]() {
    baseWindow->resetTickets();                         // zeruje liczniki biletów
    ui->stackedWidget->setCurrentWidget(baseWindow);   // przełącza na ekran główny
});


Sygnał finished() jest podłączony do slotu w AppBase, który resetuje bilety i przełącza QStackedWidget z powrotem na BaseWindow.


5. Zmiana liczby biletów — bilet normalny


Połączenia sygnałów w konstruktorze 


connect(ui->normalTicketAdd,   &QPushButton::clicked, this, &BaseWindow::addNormalTickedCount);
connect(ui->normalTicketMinus, &QPushButton::clicked, this, &BaseWindow::minusNormalTickedCount);


Sloty dodawania i odejmowania 


void BaseWindow::addNormalTickedCount()
{
    ui->normalTicketAmount->stepUp();   // zwiększa QSpinBox o 1 (max 10)
    updateSum();
}

void BaseWindow::minusNormalTickedCount()
{
    ui->normalTicketAmount->stepDown();  // zmniejsza QSpinBox o 1 (min 0)
    updateSum();
}


Aktualizacja sumy i przycisku "Kup" — updateSum() 


void BaseWindow::updateSum()
{
    int moneyValue = ui->normalTicketAmount->value() * 500;   // 5,00 zł za bilet normalny
    moneyValue += ui->reducedTicketAmount->value() * 250;      // 2,50 zł za bilet ulgowy
    QString money = QString("%1,%2 zł").arg(moneyValue / 100).arg(moneyValue % 100, 2, 10, QChar('0'));
    ui->sumValue->setText(money);

    ui->buyButton->setEnabled(!isticketcount0());  // "Kup" aktywny tylko gdy liczba biletów > 0
}


