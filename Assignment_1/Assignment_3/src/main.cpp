#include "../include/logger.hpp"
#include "../include/int_calculator.hpp"
#include "../include/template_calculator.hpp"
#include "../include/print_logger.hpp"
#include "../include/file_logger.hpp"

bool test_int_calculator(Logger* l)
{
    IntCalculator c(l);

    const auto s = c.sum(10, 2);
    const auto p = c.multiply(s, 2);

    return p == 24;
}

bool test_template_calculator(Logger* l)
{
    TemplateCalculator<float> c(l);
	//TemplateCalculator<string> cs(l); //error C2665 : 'std::to_string' : none of the 9 overloads could convert all the argument types
    
    int s = c.sum(1, 9);
    int p = c.multiply(s, 1.5);
    //const string greeting = cs.sum("Hello ", "World!");
    return p == 15.f /*&& greeting == "Hello World!"*/;
}

int main(int argc, char **argv)
{

    
    PrintLogger pl;
    FileLogger fl("my_log.txt");
    Logger* l = &fl; // change this to &fl to switch strategy

    printf("Testing int calculator:\n");
    auto was_success = test_int_calculator(l);
    printf(was_success ? "success!\n" : "failure!\n");

    printf("\n");

    printf("testing template calculator:\n");
    was_success = test_template_calculator(l);
    printf(was_success ? "success!\n" : "failure!\n");
}

