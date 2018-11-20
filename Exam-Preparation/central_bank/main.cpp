#include "CentralBank.h"
#include "ConcreteObserver.h"

int main() {
	CentralBank bank("Unicredit");


	Currency* first = new Currency("lv", 1.9);
	Currency* second = new Currency("eu", 2.3);
	Currency* third = new Currency("dl", 2.5);

	ConcreteObserver* observer1 = new ConcreteObserver("gosho");
	ConcreteObserver* observer2 = new ConcreteObserver("tosho");
	ConcreteObserver* observer3 = new ConcreteObserver("pesho");
	ConcreteObserver* observer4 = new ConcreteObserver("mosho");
	

	bank.addCurrency(first);
	bank.addCurrency(second);
	bank.addCurrency(third);
	bank.Register(observer1);
	bank.Register(observer2);
	bank.Register(observer3);
	bank.Register(observer4);

	bank.setRate("lv", 1.7);
	bank.unregister("gosho");
	bank.setRate("eu", 2.2);



	return 0;
}