#include <iostream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

const int CATEGORY = 3;

class sportActivity {
    protected:
        string *sport = new string[CATEGORY];
        float *price = new float[CATEGORY];
        int startTime[13], endTime[13];
        int num;
        int *bmtbooked = new int[13];
        int *bballbooked = new int[13];
        int *fballbooked = new int[13];
    public:
        sportActivity()
        {
			sport[0]= "Badminton";
			sport[1]= "BasketBall";
			sport[2]= "FootBall";
			price[0]= 25;
			price[1]= 30;
			price[2]= 45;
    	}
    	
        void pricelist() 
        {	
        	for (int i = 0; i < CATEGORY; i++) {
        	cout << setw(66) << i + 1 << ". ";
            cout << sport[i] << " One Hour   \t:RM" << price[i] << endl;
        	}
        }
        
        void setTime(){
            startTime[0] = 10; endTime[0] = 11;
            startTime[1] = 11; endTime[1] = 12;
            startTime[2] = 12; endTime[2] = 13;
            startTime[3] = 13; endTime[3] = 14;
            startTime[4] = 14; endTime[4] = 15;
            startTime[5] = 15; endTime[5] = 16;
            startTime[6] = 16; endTime[6] = 17;
            startTime[7] = 17; endTime[7] = 18;
            startTime[8] = 18; endTime[8] = 19;
            startTime[9] = 19; endTime[9] = 20;
            startTime[10] = 20; endTime[10] = 21;
            startTime[11] = 21; endTime[11] = 22;
            startTime[12] = 22; endTime[12] = 23;
        }

        void deletememory(){
            delete [] sport;
            delete [] price;
            delete [] bmtbooked;
            delete [] bballbooked;
            delete [] fballbooked;
        }

        friend void mainpage();
};
class customer {
	protected:
		string name, gamil, contact;
		int age; 
	public:
		void customerInfo() 
        {
            cin.sync();
			cout << "\n\t\t\t\t\t\t\t\tEnter name: ";
			getline(cin, name);
			cout << "\n\t\t\t\t\t\t\t\tEnter age: ";
			cin >> age;
            cin.sync();
			cout << "\n\t\t\t\t\t\t\t\tEnter contact number: ";
			getline(cin, contact);
	}
    friend class memberShip;
};

class badminton : public sportActivity {
    private:
        int choice;
        int numbookings = 0;
        int TimeStart[12];
        int TimeEnd[12];
    public:
    
    void showFreeTime(){
        cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
        cout << "\t\t\t\t\t\t\t\t|                   |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  Free time slots: |" << endl;
        cout << "\t\t\t\t\t\t\t\t|___________________|" << endl;
        for(int i = 0; i < 13; i++){
            if(bmtbooked[i] != 1){
                cout << "\t\t\t\t\t\t\t\t|[" << setw(2) << i + 1 << "]. " << setw(2) << startTime[i] << ":00 - " << setw(2) << endTime[i] << ":00|" << endl;
                cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
            }
            else{
                cout << "\t\t\t\t\t\t\t\t|[" << setw(2) << i + 1 << "]. " << setw(2) << startTime[i] << ":00 - " << setw(2) << endTime[i] << ":00| Booked!!!" << endl;
                cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
            }
        }
    }

    void bookAppointment(){
        showFreeTime();
        cout << "\n\t\t\t\t\t\tPlease enter the time slot you would like to book: ";
        cin >> choice;
        choice--;
        TimeStart[numbookings] = startTime[choice];
        TimeEnd[numbookings] = endTime[choice];
        bmtbooked[choice] = 1;
        numbookings++;
    }

    void displayBookings(){
        cout << "\t\t\t\t\t\tYour appointment is booked for: " << endl;
        cout << "\t\t\t\t\t\tStarting time\t: " << TimeStart[numbookings-1]  << ":00" << endl;
        cout << "\t\t\t\t\t\tEnding time\t: " << TimeEnd[numbookings-1] << ":00" << endl;
    }

   void showAllTimeSlots(){
        if(numbookings ==0){
        cout << "\t\t\t\t\t\t\t\t     Not Bookings" << endl << endl;
        }
        else{
            cout <<"\t\t\t\t\t\t\t\t     All time slots: " << endl;
            for(int i = 0; i < numbookings; i++){
                cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]. " << TimeStart[i] << ":00" << " - " << TimeEnd[i] << ":00" << endl;
            }
            cout << endl;
        }
        
    }

    int checkTimeConflict(int i, int j) { //check if there is any conflict
        if (TimeStart[i] == TimeStart[j]) {
            return 1;
        }
    }

    int hasTimeConflict() { //pass all the to time checkTimeConflict and check if there is any conflict
		int x;
        for (int i = 0; i < numbookings; i++) 
        {
            for (int j = i + 1; j < numbookings; j++) 
            {
				x = checkTimeConflict(i, j);
                if (x == 1) {
                    return 1;
                }
            }
        }
        return 0;
    }

    void deletetimeTaken(){
        numbookings-=1;
    }

    void deleteBooking(){
            cout << "\t\t\t\t\t\twhat time slot you want to delete";
            cin >> num;
            num--;
            for (int i = num; i < numbookings; i++) {
            {   
                TimeStart[i] = TimeStart[i+1];
                TimeEnd[i] = TimeEnd[i+1];
            }
            numbookings--;
        }
    }

    int getBmtDuration(){
        return numbookings;
    }

    friend class payment;
    
};

class basketball : public sportActivity {
    private:
        int numBMT = 0;
        int choice;
        int numbookings = 0;
        int TimeStart[12];
        int TimeEnd[12];
    public:

    void showFreeTime(){
        cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
        cout << "\t\t\t\t\t\t\t\t|                   |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  Free time slots: |" << endl;
        cout << "\t\t\t\t\t\t\t\t|___________________|" << endl;
        for(int i = 0; i < 13; i++){
            if(bballbooked[i] != 1){
                cout << "\t\t\t\t\t\t\t\t|[" << setw(2) << i + 1 << "]. " << setw(2) << startTime[i] << ":00 - " << setw(2) << endTime[i] << ":00|" << endl;
                cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
            }
            else{
                cout << "\t\t\t\t\t\t\t\t|[" << setw(2) << i + 1 << "]. " << setw(2) << startTime[i] << ":00 - " << setw(2) << endTime[i] << ":00| Booked!!!" << endl;
                cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
            }
        }
    }

    void bookAppointment(){
        showFreeTime();
        cout << "\n\t\t\t\t\t\tPlease enter the time slot you would like to book: ";
        cin >> choice;
        choice--;
        TimeStart[numbookings] = startTime[choice];
        TimeEnd[numbookings] = endTime[choice];
        bballbooked[choice] = 1;
        numbookings++;
    }
    void displayBookings(){
        cout << "\t\t\t\t\t\tYour appointment is booked for: " << endl;
        cout << "\t\t\t\t\t\tStarting time\t: " << TimeStart[numbookings-1] << ":00" << endl;
        cout << "\t\t\t\t\t\tEnding time\t: " << TimeEnd[numbookings-1] << ":00" << endl;
    }

    void showAllTimeSlots(){
        if(numbookings == 0){
            cout << "\t\t\t\t\t\t\t\t     Not Bookings" << endl << endl;
        }
        else{
            cout << "\t\t\t\t\t\t\t\t     All time slots: " << endl;
            for(int i = 0; i < numbookings; i++){
                cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]. " << TimeStart[i]<< ":00" << " - " << TimeEnd[i]<< ":00" << endl;
            }
            cout << endl;
        }
    }

    int checkTimeConflict(int i, int j) { //check if there is any conflict
        if (TimeStart[i] == TimeStart[j]) {
            return 1;
        }
    }

    int hasTimeConflict() { //pass all the to time checkTimeConflict and check if there is any conflict
		int x;
        for (int i = 0; i < numbookings; i++) 
        {
            for (int j = i + 1; j < numbookings; j++) 
            {
				x = checkTimeConflict(i, j);
                if (x == 1) {
                    return 1;
                }
            }
        }
        return 0;
    }

    void deletetimeTaken(){
        numbookings-=1;
    }

    void deleteBooking(){
            cout << "\t\t\t\t\t\twhat time slot you want to delete";
            cin >> num;
            num--;
            for (int i = num; i < numbookings; i++) {
            {   
                TimeStart[i] = TimeStart[i+1];
                TimeEnd[i] = TimeEnd[i+1];
            }
            numbookings--;
        }
    }

    int getBballDuration(){
        return numbookings;
    }

    friend class payment;

};

class football : public sportActivity {
    private:
        int choice;
        int numbookings = 0;
        int TimeStart[12];
        int TimeEnd[12];
    public:

    void showFreeTime(){
        cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
        cout << "\t\t\t\t\t\t\t\t|                   |" << endl;
        cout << "\t\t\t\t\t\t\t\t|  Free time slots: |" << endl;
        cout << "\t\t\t\t\t\t\t\t|___________________|" << endl;
        for(int i = 0; i < 13; i++){
            if(fballbooked[i] != 1){
                cout << "\t\t\t\t\t\t\t\t|[" << setw(2) << i + 1 << "]. " << setw(2) << startTime[i] << ":00 - " << setw(2) << endTime[i] << ":00|" << endl;
                cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
            }
            else{
                cout << "\t\t\t\t\t\t\t\t|[" << setw(2) << i + 1 << "]. " << setw(2) << startTime[i] << ":00 - " << setw(2) << endTime[i] << ":00| Booked!!!" << endl;
                cout << "\t\t\t\t\t\t\t\t_____________________" << endl;
            }
        }
    }

    void bookAppointment(){
        showFreeTime();
        cout << "\n\t\t\t\t\t\tPlease enter the time slot you would like to book: ";
        cin >> choice;
        choice--;
        TimeStart[numbookings] = startTime[choice];
        TimeEnd[numbookings] = endTime[choice];
        fballbooked[choice] = 1;
        numbookings++;
    }
    void displayBookings(){
        cout << "\t\t\t\t\t\t\t\tYour appointment is booked for: " << endl;
        cout << "\t\t\t\t\t\t\t\tStarting time\t: " << TimeStart[numbookings-1]<< ":00"  << endl;
        cout << "\t\t\t\t\t\t\t\tEnding time\t: " << TimeEnd[numbookings-1]<< ":00" << endl;
    }

    void showAllTimeSlots(){
        if(numbookings == 0){
            cout << "\t\t\t\t\t\t\t\t     Not Bookings" << endl<< endl;
        }
        else{
            cout << "\t\t\t\t\t\t\t\t     All time slots: " << endl;
            for(int i = 0; i < numbookings; i++){
                cout << "\t\t\t\t\t\t\t\t[" << i+1 << "]. " << TimeStart[i]<< ":00" << " - " << TimeEnd[i]<< ":00" << endl;
            }
            cout << endl;
        }

    }

    int checkTimeConflict(int i, int j) { //check if there is any conflict
        if (TimeStart[i] == TimeStart[j]) {
            return 1;
        }
    }

    int hasTimeConflict() { //pass all the to time checkTimeConflict and check if there is any conflict
		int x;
        for (int i = 0; i < numbookings; i++) 
        {
            for (int j = i + 1; j < numbookings; j++) 
            {
				x = checkTimeConflict(i, j);
                if (x == 1) {
                    return 1;
                }
            }
        }
        return 0;
    }

    void deletetimeTaken(){
        numbookings-=1;
    }

    void deleteBooking(){
            cout << "\t\t\t\t\t\t\t\twhat time slot you want to delete";
            cin >> num;
            num--;
            for (int i = num; i < numbookings; i++) {
            {   
                TimeStart[i] = TimeStart[i+1];
                TimeEnd[i] = TimeEnd[i+1];
            }
            numbookings--;
        }
    }

    int getfballDuration(){
        return numbookings;
    }

    friend class payment;
};

class memberShip : public customer {
    protected:
        char response;
        float discount = 0;
        string regName;
        int regAge, regFee = 0, memberType, memberPlan;
        string regContact, regGamil;
        int memberID;
    public:
        void chooseMemberType() {
            cout << "\t\t\t\t\tPlease enter your memberID :";
            cin >> memberID;
            cout << "\t\t\t\t\t\t\t\tChoose your member type" << endl;
            cout << "\t\t\t\t\t\t\t\t.=====================. " << endl;
            cout << "\t\t\t\t\t\t\t\t|`-------------------'| " << endl;
            cout << "\t\t\t\t\t\t\t\t||     1. Gold       || " << endl;
            cout << "\t\t\t\t\t\t\t\t|`-------------------'| " << endl;
            cout << "\t\t\t\t\t\t\t\t||     2. Silver     || " << endl;
            cout << "\t\t\t\t\t\t\t\t|`-------------------'| " << endl;
            cout << "\t\t\t\t\t\t\t\t||     3. Bronze     || " << endl;
            cout << "\t\t\t\t\t\t\t\t|`-------------------'| " << endl;
            cout << "\t\t\t\t\t\t\t\tEnter your choice: ";
            cin >> memberType;
        }
        void getDiscount() {
            if (memberType == 1) {
                discount = 0.2;
                cout << "\n\t\t\t\t\t\t\t  Welcome " << name << " You are a Gold member." << endl;
                cout << "\t\t\t\t\t\t\t  You will get a 20% discount." << endl<<endl;
            }
            else if (memberType == 2) {
                discount = 0.1;
                cout << "\n\t\t\t\t\t\t  Welcome " << name << " You are a Silver member." << endl;
                cout << "\t\t\t\t\t\t  You will get a 10% discount." << endl<< endl;
            }
            else if (memberType == 3) {
                discount = 0.05;
                cout << "\n\t\t\t\t\t\t  Welcome " << name << " You are a Bronze member." << endl;
                cout << "\t\t\t\t\t\t  You will get a 5% discount." << endl<< endl;
            }
            else {
                cout << "\t\t\t\t\tInvalid input. Please try again." << endl;
                chooseMemberType();
            }
        }

        void chooseMemberPlan(){
            cout << "\t\t\t\t\t\tChoose what plan you want to subscribe" << endl;
            cout << "\t\t\t\t\t\t.=======================================================. " << endl;
            cout << "\t\t\t\t\t\t|`-----------------------------------------------------'| " << endl;
            cout << "\t\t\t\t\t\t||1. Gold   - get 20% discount - register fee is RM1000|" << endl;
            cout << "\t\t\t\t\t\t|`-----------------------------------------------------'| " << endl;
            cout << "\t\t\t\t\t\t||2. Silver - get 10% discount - register fee is RM500 ||" << endl;
            cout << "\t\t\t\t\t\t|`-----------------------------------------------------'| " << endl;
            cout << "\t\t\t\t\t\t||3. Bronze - get 5% discount  - register fee is RM300 ||" << endl;
            cout << "\t\t\t\t\t\t|`-----------------------------------------------------'| " << endl;
            cout << "\t\t\t\t\t\tEnter your choice: ";
            cin >> memberPlan;
        }

        void successfulRegistration() {
            cout << "\t\t\t\t\t\t================================================================" << endl;
            cout << "\t\t\t\t\t\t|         You Have Successfully Registered As a Member.        |" << endl;
            cout << "\t\t\t\t\t\t================================================================" << endl;
            if (memberPlan == 1) {
                regFee = 1000;
                discount = 0.2;
                srand(time(0));
                memberID = (rand() % 1000) + 1;
                cout << "\t\t\t\t\t\t" << regName << "you have successfully registered as a member.\t" << endl;
                cout << "\t\t\t\t\t\tYour membership type  :   " << "Gold member"   << endl;
                cout << "\t\t\t\t\t\tYour membership ID    :   " << memberID        << endl;
                cout << "\t\t\t\t\t\tYour registration fee :  RM" << regFee          << endl;
                cout << "\t\t\t\t\t\tYou will get          :   " << " 20% discount." << endl;

            }
            else if (memberPlan == 2) {
                regFee = 500;
                discount = 0.1;
                srand(time(0));
                memberID = (rand() % 1000) + 1;
                cout << "\t\t\t\t\t\t" << regName << "you have successfully registered as a member.\t" << endl;
                cout << "\t\t\t\t\t\tYour membership type  :  " << "Silver member"   << endl;
                cout << "\t\t\t\t\t\tYour membership ID    :  " << memberID        << endl;
                cout << "\t\t\t\t\t\tYour registration fee :  RM" << regFee          << endl;
                cout << "\t\t\t\t\t\tYou will get          :  " << " 10% discount." << endl;
            }
            else if (memberPlan == 3) {
                regFee = 200;
                discount = 0.05;
                srand(time(0));
                memberID = (rand() % 1000) + 1;
                cout << "\t\t\t\t\t\t" << regName << "you have successfully registered as a member.\t" << endl;
                cout << "\t\t\t\t\t\tYour membership type  :  " << "Bronze member"   << endl;
                cout << "\t\t\t\t\t\tYour membership ID    :  " << left << memberID        << endl;
                cout << "\t\t\t\t\t\tYour registration fee :  RM" << regFee          << endl;
                cout << "\t\t\t\t\t\tYou will get          :  " << "5% discount." << endl;
            }
            else {
                cout << "\t\t\t\t\t\tInvalid input. Please try again." << endl;
                chooseMemberPlan();
            }
        }
        void registerForm(){
            cout << "\t\t\t\t\t\t-------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t|           Welcome to the registration page          |" << endl;
            cout << "\t\t\t\t\t\t-------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\tPlease fill in the form below to register as a member" << endl;
            cout << "\t\t\t\t\t\tEnter your name : " ;
            cin.sync();
            getline(cin, regName);
            cout << "\t\t\t\t\t\tEnter your age : " ;
            cin >> regAge;
            cout << "\t\t\t\t\t\tEnter your contact number : " ;
            cin.sync();
            getline(cin, regContact);
        }
        void registerMember() {
            cout << "\t\t\t\t\tSorry, " << name << " you are not a member yet." << endl;
            cout << "\t\t\t\t\tWould you like to register as a member?" << endl;
            cout << "\t\t\t\t\tYes enter 'Y'" << endl;
            cout << "\t\t\t\t\tNo  enter 'N'" << endl;
            cout << "\t\t\t\t\tEnter your choice: ";
            cin >> response;
            if (response == 'Y' || response == 'y') {
                registerForm();
                chooseMemberPlan();
                successfulRegistration();
            }
            else if (response == 'N' || response == 'n') {
                cout << "\t\t\t\t\tYou have chosen not to register as a member." << endl;
            }
        }
        float returndiscount()
        {return discount;}
};

class payment: public sportActivity, public memberShip{
    protected:
        int fballDuration, bballDuration, bmtDuration;
        int totalPrice;
        float Discount, totalPayment;
    public :
        payment(football &ft, basketball &bk, badminton &bmt, memberShip &member)
        {
            bmtDuration = bmt.getBmtDuration() * price[0];
            bballDuration = bk.getBballDuration() * price[1];
            fballDuration = ft.getfballDuration() * price[2];
            totalPrice = bmtDuration + bballDuration + fballDuration;
        }
        void setdiscountprice(memberShip &member)
        {
            Discount = totalPrice * member.returndiscount();
            totalPayment = totalPrice - Discount + regFee;
        }

        void receipt(football &ft, basketball &bk, badminton &bmt)
        {   
            cout << "\t\t\t\t##########  ##     ##   #######   ####    ##  ##  ####     ##      ##  ########  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      ##     ##  ##     ##  ## ##   ##  ## ###        ##    ##   ##    ##  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      ##     ##  ##     ##  ## ##   ##  ####           ##  ##    ##    ##  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      #########  #########  ##  ##  ##  ####            ####     ##    ##  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      ##     ##  ##     ##  ##   ## ##  ## ###           ##      ##    ##  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      ##     ##  ##     ##  ##    ####  ##  ####         ##      ########   ######## " << endl;
            cout << "\n\t\t\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << "\t\t\t\t\t\t\t|                     RECEIPT                    |" << endl;
            cout << "\t\t\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << "\t\t\t\t\t\t\t|               MMU SPORTS CENTRE                |" << endl;
            cout << "\t\t\t\t\t\t\t|           Persiaran Multimedia,63100           |" << endl;
            cout << "\t\t\t\t\t\t\t|               Cyberjaya,Selangor               |" << endl;
            cout << "\t\t\t\t\t\t\t|                   Malaysia                     |" << endl;
            cout << "\t\t\t\t\t\t\t|         Phone: (+603) 8234 5678 / 5950         |" << endl;
            cout << "\t\t\t\t\t\t\t|             Fax: (+603) 8234 5338              |" << endl;
            cout << "\t\t\t\t\t\t\t|                   Thank You!                   |" << endl;
            cout << "\t\t\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
            cout << "\t\t\t\t\t\t\t|your basketball duration : " << bk.getBballDuration() << "hour * one hour RM" << price[1]<< "|" << endl;
            cout << "\t\t\t\t\t\t\t|your football duration   : " << ft.getfballDuration() << "hour * one hour RM" << price[2]<< "|"<< endl;
            cout << "\t\t\t\t\t\t\t|total price \t\t    : RM" << totalPrice << "\t\t |" << endl;
            cout << "\t\t\t\t\t\t\t|you can get \t\t    : RM" << Discount << " discount\t |" << endl;
            cout << "\t\t\t\t\t\t\t|your register fee is       : RM" << regFee << "\t\t |"<< endl;
            cout << "\t\t\t\t\t\t\t|after discout you need pay : RM" << totalPayment << "\t\t |"<< endl;
            cout << "\t\t\t\t\t\t\t-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
        }
};

void makeApointment(badminton &b, basketball &bk, football &fb);
void showMainPage(badminton &b, basketball &bk, football &fb, sportActivity &spr, memberShip &member);
int main(){
    badminton bmt;
    basketball bball;
    football fball;
    sportActivity sport;
    memberShip member;
    showMainPage(bmt, bball, fball, sport,member);
    
    return 0;
}
void showMainPage(badminton &b, basketball &bk, football &fb, sportActivity &spr, memberShip &member){
    customer p;
    int choice, sportIndex;
    payment pay(fb,bk,b,member);
    char respone;
	cout << "\n\t\t\t\t\t-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
	cout << "\n\t\t\t\t\t|                                                                          |";
    cout << "\n\t\t\t\t\t|##       ###       ## ####### ##      ####### ####### ####   #### ####### |";
    cout << "\n\t\t\t\t\t| ##     ## ##     ##  ##      ##      ##      ##   ## ##  ###  ## ##      |";
    cout << "\n\t\t\t\t\t|  ##   ##   ##   ##   #####   ##      ##      ##   ## ##  ###  ## #####   |";
    cout << "\n\t\t\t\t\t|   ## ##     ## ##    ##      ##      ##      ##   ## ##       ## ##      |";
    cout << "\n\t\t\t\t\t|    ###       ###     ####### ####### ####### ####### ##       ## ####### |";
    cout << "\n\t\t\t\t\t|                                                                          |";
    cout << "\n\t\t\t\t\t-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
    cout << "\n\t\t\t\t\t|                  ----------MMU SPORTS CENTRE----------                   |";
    cout << "\n\t\t\t\t\t-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
    cout << "\n\t\t\t\t\t|                          1.Customer Info                                 |";
    cout << "\n\t\t\t\t\t|                          2.Make Apointment                               |";
	cout << "\n\t\t\t\t\t|                          3.Display Price list                            |";
	cout << "\n\t\t\t\t\t|                          4.Cancel Booking                                |";
    cout << "\n\t\t\t\t\t|                          5.List All Booking Time                         |";
    cout << "\n\t\t\t\t\t|                          6.Make payment                                  |";
    cout << "\n\t\t\t\t\t|                          7.Exit                                          |";
	cout << "\n\t\t\t\t\t-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-";
    cout << "\n\t\t\t\t\t\t\t\t   Enter your choice: ";
    cin >> choice;
    switch (choice) {
        case 1:
            p.customerInfo();
        case 2:
            makeApointment(b, bk, fb);
            showMainPage(b, bk, fb, spr,member);
            break;
        case 3:
            spr.pricelist();
            cout << "\t\t\t\t\tWould you like to book another appointment? (Y/N)";
            cin >> respone;
            if(respone == 'Y' || respone == 'y'){
                makeApointment(b, bk, fb);
            }
            showMainPage(b, bk, fb, spr,member);
            break;
        case 4:
            do{
                cout << "\t\t\t\t\t __________________________________" << endl;
                cout << "\t\t\t\t\t [                                ]" << endl;
                cout << "\t\t\t\t\t [ 1. Check Appoiment Badminton   ]" << endl;
                cout << "\t\t\t\t\t [ 2. Check Appoinment Basketball ]" << endl;
                cout << "\t\t\t\t\t [ 3. Check Appoinment Fooball    ]" << endl;
                cout << "\t\t\t\t\t [________________________________]" << endl;
                cout << "\t\t\t\t\t what sport you want to check and delete : ";
                cin >> sportIndex;
                if(sportIndex == 1){
                    do{
                    b.showAllTimeSlots();
                    b.deleteBooking();
                    cout << "\t\t\t\t\tWould you like to check again (Y/N)" ;
                    cin >> respone;
                    }while(respone == 'Y' || respone == 'y');
                }
                else if(sportIndex == 2){
                   do{
                    bk.showAllTimeSlots();
                    bk.deleteBooking();
                    cout << "\t\t\t\t\tWould you like to check again (Y/N)" ;
                    cin >> respone;
                    }while(respone == 'Y' || respone == 'y');

                }
                else if(sportIndex == 3){
                    do{
                    fb.showAllTimeSlots();
                    fb.deleteBooking();
                    cout << "\t\t\t\t\tWould you like to check again (Y/N)" ;
                    cin >> respone;
                    }while(respone == 'Y' || respone == 'y');

                }
                cout << "\t\t\t\t\tWould you like to check another sport? (Y/N) :";
                cin >> respone;
                showMainPage(b, bk, fb, spr,member);
            }while(respone == 'Y' || respone == 'y');
            break;
        case 5:
            b.setTime();
            bk.setTime();
            fb.setTime();
            cout << "\t\t\t\t\t\t\t   -------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t   |Here is all your booking time|" << endl;
            cout << "\t\t\t\t\t\t\t   -------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t\tBadminton Time Slot   "<< endl;
            cout << "\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~    " << endl;
            b.showAllTimeSlots();
            cout << "\t\t\t\t\t\t\t\tBasketball Time Slot   "<< endl;
            cout << "\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~    " << endl;
            bk.showAllTimeSlots();
            cout << "\t\t\t\t\t\t\t\tFootball Time Slot   "<< endl;
            cout << "\t\t\t\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~    " << endl;
            fb.showAllTimeSlots();
            showMainPage(b, bk, fb, spr,member);
            break;
        case 6:
            cout << "\t\t\t\t\tare you have the membership? :"<< endl;
            cout << "\t\t\t\t\tYes enter 'Y'" << endl;
            cout << "\t\t\t\t\tNo  enter 'N'" << endl;
            cout << "\t\t\t\t\tEnter your choice: ";
            cin >> respone;
            if(respone == 'Y' || respone == 'y'){
                member.chooseMemberType();
                member.getDiscount();
                pay.setdiscountprice(member);
            }
            else{
                pay.registerMember();
            }
            pay.receipt(fb,bk,b);
            showMainPage(b, bk, fb, spr,member);
            break;
            break;
        case 7:
            spr.deletememory();
            cout << endl;
            cout << "\t\t\t\t##########  ##     ##   #######   ####    ##  ##  ####     ##      ##  ########  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      ##     ##  ##     ##  ## ##   ##  ## ###        ##    ##   ##    ##  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      ##     ##  ##     ##  ## ##   ##  ####           ##  ##    ##    ##  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      #########  #########  ##  ##  ##  ####            ####     ##    ##  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      ##     ##  ##     ##  ##   ## ##  ## ###           ##      ##    ##  ##      ##" << endl;
	        cout << "\t\t\t\t    ##      ##     ##  ##     ##  ##    ####  ##  ####         ##      ########   ######## " << endl;
            cout << "\n\t\t\t\t\t\t                         /|  /|  --------------------------";
            cout << "\n\t\t\t\t\t\t                         ||__||  |                        |";
            cout << "\n\t\t\t\t\t\t                       /   O O\\__     THANK FOR SUPPORT   |";
            cout << "\n\t\t\t\t\t\t                      /          \\  Have A Nice Day ! ! ! |";
            cout << "\n\t\t\t\t\t\t                     /      \\     \\                       |";
            cout << "\n\t\t\t\t\t\t                    /   _    \\     \\-----------------------";
            cout << "\n\t\t\t\t\t\t                   /    |\\____\\     \\      ||";
            cout << "\n\t\t\t\t\t\t                  /     | | | |\\____/      ||";
            cout << "\n\t\t\t\t\t\t                 /       \\| | | |/ |     __||";
            cout << "\n\t\t\t\t\t\t                /  /  \\   -------  |_____| ||";
            cout << "\n\t\t\t\t\t\t               /   |   |           |       |";
            cout << "\n\t\t\t\t\t\t               |   |   |           |_____  |";
            cout << "\n\t\t\t\t\t\t               |  |_|_|_|          |     \\-|";
            cout << "\n\t\t\t\t\t\t               /\\                  |";
            cout << "\n\t\t\t\t\t\t              / /\\        |        /";
            cout << "\n\t\t\t\t\t\t             / /  |       |       |";
            cout << "\n\t\t\t\t\t\t         _ _/ /   |       |       |";
            cout << "\n\t\t\t\t\t\t       |____/    c_c_c_C/ \\C_c_c_c/";

            break;
        default:
            cout << "\t\t\t\t\tInvalid input. Please try again." << endl;
            showMainPage(b, bk, fb, spr,member);
    }
}

void makeApointment(badminton &b, basketball &bk, football &fb){
    sportActivity sport;
    int sportIndex;
    char choice;
    b.setTime();
    bk.setTime();
    fb.setTime();
    cout << "\n\t\t\t\t\t     .'  __________________________________________________________  '.";
    cout << "\n\t\t\t\t\t     .'                                                          '. :";
    cout << "\n\t\t\t\t\t     | |      ________________________________________________      | |";
    cout << "\n\t\t\t\t\t     | |    .:________________________________________________:.    | |";
    cout << "\n\t\t\t\t\t     | |    |                                                  |    | |";
    cout << "\n\t\t\t\t\t     | |    |            Welcome to the Sports Centre!         |    | |";
    cout << "\n\t\t\t\t\t     | |    |                                                  |    | |";
    cout << "\n\t\t\t\t\t     | |    |            __________________________            |    | |";
    cout << "\n\t\t\t\t\t     | |    |           |  |  |  |  |  |  |  |  |  |           |    | |";
    cout << "\n\t\t\t\t\t     | |    '.__________|__|__|__|__|__|__|__|__|__|__________.'    | |";
    cout << "\n\t\t\t\t\t     : '.__________________________________________________________.' :"<<endl;
    do{
        cout << "\t\t\t\t\t\t\t\t     Please select a sport: " << endl;
        cout << "\n\t\t\t\t\t     |________________________________________________________________|"<<endl;
        sport.pricelist();
        cout << "\t\t\t\t\t\t\t\t\tEnter your choice: ";
        cin >> sportIndex;
        
        if(sportIndex == 1)
        {
            do{
                b.bookAppointment();
                if (b.hasTimeConflict() == 1)
                {
                    cout << "\t\t\t\t\t\tThis time slot is already booked" << endl;
                    b.deletetimeTaken();
                }else 
                {
                    b.displayBookings();
                }
                cout << "\t\t\t\t\t\tWould you like to book another appointment? (Y/N)";
                cin >> choice;
            }
            while (choice == 'Y' || choice == 'y');
            do{
                cout << "\t\t\t\t\t\tWould you like to delete an appointment? (Y/N)";
                cin >> choice;
                if (choice == 'Y' || choice == 'y'){
                    b.showAllTimeSlots();
                    b.deleteBooking();
                }
            }while (choice == 'Y' || choice == 'y');
        }
        else if(sportIndex == 2)
        {
            do{
                bk.bookAppointment();
                if (bk.hasTimeConflict() == 1)
                {
                    cout << "\t\t\t\t\t\tThis time slot is already booked." << endl;
                    bk.deletetimeTaken();
                }else 
                {
                    bk.displayBookings();
                }
                cout << "\t\t\t\t\t\tWould you like to book another appointment? (Y/N)";
                cin >> choice;
            }
            while (choice == 'Y' || choice == 'y');
            do{
                cout << "\t\t\t\t\t\tWould you like to delete an appointment? (Y/N)";
                cin >> choice;
                if (choice == 'Y' || choice == 'y'){
                    bk.showAllTimeSlots();
                    bk.deleteBooking();
                }
            }while (choice == 'Y' || choice == 'y');
        }
        else if(sportIndex == 3){
            do{
                fb.bookAppointment();
                if (fb.hasTimeConflict() == 1)
                {
                    cout << "\t\t\t\t\t\tThis time slot is already booked." << endl;
                    fb.deletetimeTaken();
                }else 
                {
                    fb.displayBookings();
                }
                cout << "\t\t\t\t\t\tWould you like to book another appointment? (Y/N)";
                cin >> choice;
            }
            while (choice == 'Y' || choice == 'y');
            do{
                cout << "\t\t\t\t\t\tWould you like to delete an appointment? (Y/N)";
                cin >> choice;
                if (choice == 'Y' || choice == 'y'){
                    fb.showAllTimeSlots();
                    fb.deleteBooking();
                }
            }while (choice == 'Y' || choice == 'y');

        }
        else
        {
            cout << "\t\t\t\t\t\tInvalid input. Please try again." << endl;
            sport.pricelist();
            cout << "\t\t\t\t\t\tEnter your choice: ";
            cin >> sportIndex;
        }
    cout << "\t\t\t\t\t\tWould You Like To Book Another Sports? (Y/N):";
    cin >> choice;
    }while (choice == 'Y' || choice == 'y');
}