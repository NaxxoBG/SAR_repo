
#include "Feeder.h"
#include "FilterByName.h"
#include "FullFeeder.h"
#include "Monkey_Loader.h"
#include "Printer.h"

int main()
{
	Printer pr;
	Monkey_Loader ld;

	Feeder fr;
	Feeder fr2;
	Printer pr2;
	Printer pr3;
	Printer pr4;

	FullFeeder ff;

	std::unordered_set<std::string> names = { "Coco", "Mike" };
	FilterByName nf = FilterByName(names);

	ld.set_next(&pr)->set_next(&fr)->set_next(&pr2)->set_next(&nf)->set_next(&fr2)->set_next(&pr3)->set_next(&ff)->set_next(&pr4);
	ld.load();
}
