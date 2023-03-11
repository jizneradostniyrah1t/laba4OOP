#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdio.h>

class date {
private:
    int day, month, year;
public:
    void set_date_day(int day_) {
        day = day_;
    }
    void set_date_month(int month_) {
        month = month_;
    }
    void set_date_year(int year_) {
        year = year_;
    }
    int get_date_day() {
        return day;
    }
    int get_date_month() {
        return month;
    }
    int get_date_year() {
        return year;
    }
};

class common {
protected:
    char* fio;
    double price;
public:

    common() {
        fio = nullptr;
        price = -1;
    }
    common(char* fio, double price) {
        this->fio = new char[strlen(fio) + 1];
        strcpy(this->fio, fio);
        this->price = price;
    }
    common(common& ob) {
        fio = new char[strlen(ob.fio) + 1];
        strcpy(this->fio, ob.fio);
        price = ob.price;
    }
    char* get_common_fio() {
        char* p = new char[strlen(fio) + 1];
        strcpy(p, fio);
        return p;
    }
    double get_common_price() {
        return price;
    }
    void set_common_fio(char* fio) {
        if (this->fio != nullptr)
            delete[] this->fio;
        this->fio = new char[strlen(fio) + 1];
        strcpy(this->fio, fio);
    }
    void set_common_price(double price) {
        this->price = price;
    }

    ~common() {
        delete[] fio;
    }

    void out() {
        std::cout << " \n fio = " << fio;
        std::cout << " \n price  =  " << price;
    }



};



class St : public common {
private:
    char* point_from;
    char* point_to;

public:


    St() : common() {
        point_from = nullptr;
        point_to = nullptr;

    }
    St(char* fio, double price, char* point_from, char* point_to) : common(fio, price) {
        this->point_from = new char[strlen(point_from) + 1];
        strcpy(this->point_from, point_from);

        this->point_to = new char[strlen(point_to) + 1];
        strcpy(this->point_to, point_to);

    }
    St(St& ob) {
        point_from = new char[strlen(ob.point_from) + 1];
        strcpy(this->point_from, ob.point_from);
        point_to = new char[strlen(ob.point_to) + 1];
        strcpy(this->point_to, ob.point_to);

    }
    char* get_st_point_from() {
        char* p = new char[strlen(point_from) + 1];
        strcpy(p, point_from);
        return p;
    }

    void set_st_point_from(char* point_from) {
        if (this->point_from != nullptr)
            delete[] this->point_from;
        this->point_from = new char[strlen(point_from) + 1];
        strcpy(this->point_from, point_from);
    }
    void set_st_point_to(char* point_to) {
        if (this->point_to != nullptr)
            delete[] this->point_to;
        this->point_to = new char[strlen(point_to) + 1];
        strcpy(this->point_to, point_to);
    }

    ~St() {
        delete[] point_from;
        delete[] point_to;
    }
    void out() {
        common::out();
        std::cout << " \n point_from = " << point_from;
        std::cout << " \n point_to  =  " << point_to;
    }




};

class ticket : public common {
private:
    int num, numplace;
public:
    ticket() : common() {
        num = -1;
        numplace = numplace;

    }
    ticket(char* fio, double price, int num, int numplace) : common(fio, price) {
        this->num = num;
        this->numplace = numplace;

    }
    ticket(ticket& ob) {
        num = ob.num;
        numplace = ob.numplace;

    }

    void set_ticket_num(int num) {
        this->num = num;
    }
    void set_ticket_numplace(int numplace) {
        this->numplace = numplace;

    }
    int get_ticket_num() {
        return num;
    }

    int get_ticket_numplace() {
        return numplace;
    }

    void out() {
        common::out();
        std::cout << " \n number of railcar = " << num;
        std::cout << " \n number of place  =  " << numplace;
    }

};
int addall(St*& st, ticket*& t) {
    int l = 0;
    std::cin >> l;
    st = new St[l];
    t = new ticket[l];
    char buf[4096];
    double price;
    int num, numplace;
    for (int i = 0; i < l; i++) {

        std::cout << " \n enter fio ";
        std::cin >> buf;
        st[i].set_common_fio(buf);
        t[i].set_common_fio(buf);
        std::cout << " \n enter point_from ";
        std::cin >> buf;
        st[i].set_st_point_from(buf);
        std::cout << " \n enter point_to ";
        std::cin >> buf;
        st[i].set_st_point_to(buf);
        std::cout << " \n enter price of ticket ";
        std::cin >> price;
        st[i].set_common_price(price);
        t[i].set_common_price(price);
        std::cout << " \n enter num ";
        std::cin >> num;
        t[i].set_ticket_num(num);
        std::cout << " \n enter numplace ";
        std::cin >> numplace;
        t[i].set_ticket_numplace(numplace);





    }
    return l;
}
void outall(St* st, ticket* t, int l) {
    for (int i = 0; i < l; i++) {
        st[i].out();
        t[i].out();
    }
}

void infilefirst(St* st, int l, char* fileName) {

    std::ofstream offile;

    offile.open(fileName);


    if (!offile.is_open())
    {
        std::cout << "error";
        return;
    }
    else {
        std::cout << " the data is correct ";

    }

    offile << l << "\n";
    for (int i = 0; i < l; i++)
    {


        offile << st[i].get_common_fio() << '\t' << st[i].get_st_point_from() << '\t' << st[i].get_st_point_from() << '\t' << st[i].get_common_price() << std::endl;

    }





}


void infilesecond(ticket* t, int l, char* fileName) {
    std::ofstream offile;

    offile.open(fileName);


    if (!offile.is_open())
    {
        std::cout << "error";
        return;
    }
    else {
        std::cout << " the data is correct ";

    }

    offile << l << "\n";
    for (int i = 0; i < l; i++)
    {


        offile << t[i].get_common_fio() << '\t' << t[i].get_ticket_num() << '\t' << t[i].get_ticket_numplace() << '\t' << t[i].get_common_price() << std::endl;

    }
}





void scenario() {
    std::cout << "enter count tickets ";
    int l = 0;
    St* st = nullptr;
    ticket* t = nullptr;
    l = addall(st, t);
    outall(st, t, l);
    infilefirst(st, l, "data1.txt");
    infilesecond(t, l, "data2.txt");

}



int main() {
    scenario();




}





