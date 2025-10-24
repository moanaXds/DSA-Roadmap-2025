#include "main.h"

int main() 
{
	Bank b;
	b.add_New_Customer("T001", "male");
	b.add_New_Customer("T002", "female");
	b.add_New_Customer("T003", "male");

	cout << "\n--- Current Queue ---\n";

	b.DisplayQueue();

	cout << "\n--- Serving One Customer ---\n";

	b.remove_customer();


	cout << "\n--- Updated Queue ---\n";


	b.DisplayQueue();

	return 0;
}
