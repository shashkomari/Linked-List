#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
	LinkedList friendsNames;

	friendsNames.add("Nikitka");
	friendsNames.add("Andrei");
	friendsNames.add("Vasya");
	friendsNames.add("Anna");
	friendsNames.add("Mara");
	friendsNames.add("Vichka");
	friendsNames.add("Vasya");

	friendsNames.show();
	/*LinkedList::Iterator iter = friendsNames.getIterator();*/

	//iter.getValue(); // "Nikitka"
	//iter.next(); // iter++
	//iter.getValue(); // "Andrei"
	//iter.next(); // iter++
	//iter.getValue(); // "Anna"

	std::string nameToDelete = "Vasya";
	bool removed = friendsNames.removeAll(nameToDelete);
	if (removed) {
		cout << "My udalili vseh druzei s imenem " << nameToDelete << " iz druzei" << endl;
	}
	else {
		cout << "Chtoby udalit vseh druzei s imenem " << nameToDelete << " nado snachala podruzhitca s nimi" << endl;
	}

	friendsNames.show();

	return 0;
}