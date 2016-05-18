// ..................................................  
// CDate driver 
// Adapted from Hagit Schechter, Jan 2007 for 2016S2
// ..................................................

#include "CDate.h"
#include "Unit.h"

int main(void)
{
    CDate myDate0(2015,1,1);
    CDate myDate1(-1,"May",25);
    CDate myDate2(2012,"April",31);
    CDate myDate3(2011,"February",29);
    CDate myDate4(2000,"February",29);
    CDate myDate5(2014,"December",32);
    CDate myDate6(2014,"December",31);
    CDate myDate7(2010,"November",31);
    CDate myDate8(2010,"November",30);

    CDate* date9 = new CDate(2010, 2, 29); 
    CDate* date10 = new CDate(2012, 2, 29); 
    CDate* date11 = new CDate(2014, 9, 5); 

    myDate0.print();
    myDate1.print();
    myDate2.print();
    myDate3.print();
    myDate4.print();
    myDate5.print();
    myDate6.print();
    myDate7.print();
    myDate8.print();

    date9->print(); 
    date10->print(); 
    date11->print();

    Unit unit; 
    unit.assertEquals("myDate0", 20150101, myDate0.getDate() ); 
    unit.assertEquals("myDate1",        0, myDate1.getDate() ); 
    unit.assertEquals("myDate2",        0, myDate2.getDate() ); 
    unit.assertEquals("myDate3",        0, myDate3.getDate() ); 
    unit.assertEquals("myDate4", 20000229, myDate4.getDate() ); 
    unit.assertEquals("myDate5",        0, myDate5.getDate() ); 
    unit.assertEquals("myDate6", 20141231, myDate6.getDate() ); 
    unit.assertEquals("myDate7",        0, myDate7.getDate() ); 
    unit.assertEquals("myDate8", 20101130, myDate8.getDate() ); 
    unit.assertEquals("date9",          0, date9->getDate() ); 
    unit.assertEquals("date10",  20120229, date10->getDate() ); 
    unit.assertEquals("date11",  20140905, date11->getDate() ); 
    unit.printResults(); 

    delete(date9); 
    delete(date10); 
    delete(date11); 

#ifdef _WIN32
    system("PAUSE"); // needed for windows to prevent the program from terminating and the command window to close
#endif

    return 0;
}
