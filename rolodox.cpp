#include <iostream>
#include <limits>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;




class Entry
{
    private:
    string first_name, last_name, street_address, state_name, town_city, email_address, phone_number;
    int zip_code;
    public:
    Entry (void): first_name(), last_name(), street_address(), state_name(), town_city(),email_address(), zip_code(0),phone_number()
    {
    }
    Entry (string first_name, string last_name): street_address(), town_city(), email_address(),zip_code (0),phone_number()
    {
    }
    Entry (const Entry & e): first_name (e.first_name), last_name(e.last_name), street_address(e.street_address), state_name(e.state_name), town_city (e.town_city), email_address(e.email_address), zip_code(e.zip_code), phone_number(e.phone_number)
    {
    }
    
    string get_first_name() const
    {
        return first_name;
    }
    string get_last_name() const
    {
        return last_name;
    }
    string get_street_address() const
    {
        return street_address;
    }
    string get_state_name() const
    {
        return state_name;
    }
    string get_town_city() const
    {
        return town_city;
    }
    string get_email_address() const
    {
        return email_address;
    }
    int get_zip_code() const
    {
        return zip_code;
    }
    string get_phone_number() const
    {
        return phone_number;
    }
    void set_first_name(string first_n)
    {
        first_name = first_n;
    }
    void set_last_name(string last_n)
    {
        last_name = last_n;
    }
    void set_street_address(string street_a)
    {
        street_address = street_a;
    }
    void set_state_name(string state_n)
    {
        state_name = state_n;
    }
    void set_town_city(string town_c)
    {
        town_city =  town_c;
    }
    void set_email_address(string email_a)
    {
        email_address = email_a;
    }
    void set_zip_code(int zip_c)
    {
        zip_code = zip_c;
    }
    void set_phone_number (string phone_n)
    {
        phone_number = phone_n;
    }
    
    void input_entry();
    
    void output_entry();
    bool isEqual(Entry e){return e.first_name == first_name && e.last_name == last_name &&
   e.street_address == street_address && e.town_city == town_city &&
   e.state_name == state_name && e.zip_code == zip_code && e.email_address == email_address &&
   e.phone_number == phone_number;}
       
};

void print_output(vector<Entry> & record);
void delete_entry(vector<Entry> & record, short sum);
void edit_submenu(vector <Entry> & record);
void sub_menu(vector<Entry> & record);

int main()
{
    
    vector<Entry> record;
    char choice;
    bool round = true;
    
    do
    {
        cout << "\n\t\t* MAIN MENU *\n\t-------------------------\n\t1) Add Entry \n\t-------------------------"
             << "\n\t2) Edit Entry\n\t-------------------------"
             << "\n\t3) Delete Entry\n\t-------------------------"
             << "\n\t4) Find Entry\n\t-------------------------"
             << "\n\t5) Print Entry\n\t-------------------------"
             << "\n\t6) Quit\n\t-------------------------"<<"\n\n\t[ CHOICE ] : ";
        
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin.clear();
        choice = static_cast<char>(toupper(choice));
        switch (choice)
        {
            case '1' :  case 'a' :
            {
             
                
                Entry entry;
                entry.input_entry();
                record.push_back(entry);
                
            }
            break;
                
            case '2' :  case 'e' :
            {
                
                edit_submenu(record);
            }
            break;
                
            case '3' :  case 'd' :
            {
             
              
              cout << "\nChoose only one Contact to delete one by one: ";
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                }
                short sum;
                cin >> sum;

                delete_entry(record, sum-1);
            }
            break;
            case '4' :  case 'f' :
            {
             
                sub_menu(record);
                
                
            }
            break;
            case '5' :  case 'p' :
            {
                print_output(record);
            }
            break;
            case '6' :  case 'q' :
            {
             
                round = false;
                cout <<"\n\nThank you for using the Rolodox entry!!!\n\nEndeavor to have a localized day...";
            }
            break;
            default:
                cerr << "\n\n\tInvalid choice please see option and choice carefully!!!\n\n"<< endl;
            break;
                
        }
    }while (round);
    
    
    return 0;
}

    
void sub_menu(vector<Entry> & record)
{
    char sub;
    string search;
    
    cout << "\n\t\t* FIND MENU *\n\t-------------------------\n\t1) Find by Name\n\t-------------------------"
         << "\n\t2) Find by Address\n\t-------------------------"
         << "\n\t3) Find by Phone number\n\t-------------------------"
         << "\n\t4) Find by Email address\n\t-------------------------"
         << "\n\t5) Return to Main Menu\n\t-------------------------"
         <<"\n\n\t[ CHOICE ] : ";
    
    cin >> sub;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.clear();
    sub = static_cast<char>(toupper(sub));
    switch(sub)
    {
               case '1' :  case 'n' :
               {
                   cout << "\n Enter First / Last Name to Find The Data: ";
                 
                   getline(cin,search);
                   for (vector<Entry>::size_type i= 0; i < record.size(); i++)
                   {
                       if(record[i].get_first_name().find(search) != string::npos || record[i].get_last_name().find(search) !=string::npos)
                       {
                           record[i].output_entry();
                       }
                   }
               }
                break;
                   
               case '2' :  case 'a' :
               {
                   cout << "\n Enter Street address / city / state name to Find The Data: ";
                   getline(cin,search);
                     for (vector<Entry>::size_type i= 0; i < record.size(); i++)
                     {
                         if(record[i].get_street_address().find(search) != string::npos || record[i].get_state_name().find(search) !=string::npos || record[i].get_town_city().find(search) !=string::npos)
                         {
                             record[i].output_entry();
                         }
                     }
               }
               break;
                   
               case '3' :  case 'p' :
               {
                cout << "\n Enter Phone Number to Find The Data: ";
                
                  getline(cin,search);
                  for (vector<Entry>::size_type i= 0; i < record.size(); i++)
                  {
                      if(record[i].get_phone_number().find(search) != string::npos)
                      {
                          record[i].output_entry();
                      }
                  }
               }
               break;
               case '4' :  case 'e' :
               {
                cout << "\n Enter E-mail address to Find The Data: ";
                
                  getline(cin,search);
                  for (vector<Entry>::size_type i= 0; i < record.size(); i++)
                  {
                      if(record[i].get_email_address().find(search) != string::npos)
                      {
                          record[i].output_entry();
                      }
                  }
               }
               break;
               case '5' :  case 'm' :
               {
                    
               }
               break;
               default:
                   cerr << "\n\n\tInvalid choice please see option and choice carefully!!!\n\n"<< endl;
               break;
        
    }
}






void edit_submenu(vector <Entry> & record)
{
   print_output(record);
    short index;
    cout <<"\nPlease select the contact from record: ";
    cin >> index;
    
    if( index >=0 && index <= record.size())
      
    {
           cout <<"\nPlease select the contact from record: ";
           cin >> index;
           cin.ignore();
        Entry edited = record[index];
        
      string new_first_name, new_last_name, new_street_address, new_town_city, new_state_name, new_email_address, new_phone_number;
      int new_zip_code;
        cin.ignore();
      ifstream in_file;
      ofstream out_file;
      out_file.open ("entry.txt");
      
      cout <<"\nPlease Enter New Name: ";
      getline(cin,new_first_name);
      new_first_name [0] = toupper(new_first_name[0]);
      edited.set_first_name(new_first_name);
      out_file << new_first_name << endl;
              
      cout <<"\nPlease Enter Last Name: ";
      getline(cin,new_last_name);
      new_last_name[0] = toupper(new_last_name[0]);
      edited.set_last_name(new_last_name);
      out_file << new_last_name << endl;
              
      cout <<"\nPlease Enter New Street Address: ";
      getline(cin,new_street_address);
      new_street_address[0] = toupper(new_street_address[0]);
      edited.set_street_address(new_street_address);
      out_file << new_street_address << endl;
              
      cout <<"\nPlease Enter New Town/City: ";
      getline(cin,new_town_city);
      new_town_city[0] = toupper(new_town_city[0]);
      edited.set_town_city(new_town_city);
      out_file << new_town_city << endl;
               
      cout <<"\nPlease Enter New State Name: ";
      getline(cin,new_state_name);
      new_state_name[0] = toupper(new_state_name[0]);
      edited.set_state_name(new_state_name);
      out_file << new_state_name << endl;
            
      cout <<"\nPlease Enter New zip code: ";
      cin  >> new_zip_code;
     if (new_zip_code >= 99999)
        {
          cout << "\ninvalid zip code\n\n";
          cin.clear();
          cin >> new_zip_code;
        }
      edited.set_zip_code(new_zip_code);
      out_file << new_zip_code << endl;
                    
    
      cout <<"\nPlease Enter New E-mail Address: ";
        if(cin.peek() == '\n')
                      {
                          cin.ignore();
                      }
      getline(cin,new_email_address);
      edited.set_email_address(new_email_address);
      out_file << new_email_address << endl;
    
      cout <<"\nPlease Enter New Phone Number: ";
      getline(cin,new_phone_number);
      edited.set_phone_number(new_phone_number);
      out_file << new_phone_number << endl;
                    
      out_file.close();
      out_file.clear();
    }
    else
      {
          cout << "\nThere is no contact list in Rolodox Entry.\n\n";
      }
}

void delete_entry(vector<Entry> & record, short sum)
{
  vector<Entry>::size_type pos = sum-1;
  vector<Entry>::size_type i;
  if(pos < record.size() && pos >= record.size() )
  {
    for (i=pos+1;i!=record.size();i++)
    {
      record[i-1]= record[i];
    }
      record.pop_back();
  }
    else
    {
        cout <<" there is nothing to earse"<< endl;
    }
}


 
 void print_output(vector<Entry> & record)
{
    cout << endl;
    for(vector<Entry>::size_type i = 0; i < record.size(); i++)
    {
        cout<< "\n\n\t\t* PRINT LIST *\n----------------------------------------\n" << i+1 << ".   ROLODOX ENTRY \n----------------------------------------\n";
        record [i].output_entry();
    }
}

void Entry::output_entry()

   {
       
       ifstream infile;
       infile.open ("entry.txt", ios::app);
       
       infile.ignore();
       getline (infile,first_name);
       getline (infile,last_name);
       cout << "\nFULL NAME : " << first_name << " " << last_name << endl;
       
       
       getline(infile, street_address);
       cout << "\nFULL ADDRESS : "<< street_address << endl;
       
       
       infile >> town_city ;
       cout <<"\nTOWN OR CITY : " << town_city << endl;
       
       infile >> state_name;
       cout << "\nSTATE NAME: " << state_name << endl;
       
       infile >> zip_code  ;
       cout <<"\nZIP CODE : " << zip_code << endl ;
       
       infile >> email_address;
       cout <<"\nE-MAIL ADDRESS: " << email_address << endl;
       
       infile >> phone_number;
       cout << "\nPHONE NUMBER: "<<phone_number << endl;
       cout <<"\n*****************************************\n\n"<<endl;
       
       infile.close();
       infile.clear();
       
       
   }

void Entry::input_entry()
{
    ofstream outfile;
    outfile.open("entry.txt", ios::app);
    
    
    cout <<"\nPlease enter New contact first name: ";
    getline(cin,first_name);
    first_name [0] = toupper(first_name[0]);
    outfile << first_name << endl;
    
    cout <<"\nPlease enter New contact last name: ";
    getline(cin,last_name);
    last_name [0] = toupper(last_name[0]);
    outfile << last_name << endl;

    cout <<"\nPlease enter New contact address including number and street: ";
    cin.clear();
    if (cin.peek()== '\n')
    {
       cin.ignore();
    }
    getline(cin,street_address);
    outfile << street_address << endl;
    
    cout <<"\nPlease enter New contact town/city name: ";
    cin.clear();
    if (cin.peek() =='\n')
    {
        cin.ignore();
    }
    getline(cin,town_city);
    town_city [0] = toupper(town_city[0]);
    outfile << town_city << endl;
    
    cout <<"\nPlease enter New contact state name: ";
    cin.clear();
    if(cin.peek() == '\n')
    {
        cin.ignore();
        
    }
    getline(cin,state_name);
    state_name [0] = toupper(state_name[0]);
    outfile << state_name << endl;
    
    cout <<"\nPlease enter New contact zip code: ";
    cin  >> zip_code;
           if (zip_code >= 99999)
           {
               cout << "invalid zip code\n\n";
               cin.clear();
           }
        
    outfile << zip_code << endl;
    
    
    cout <<"\nPlease enter New contact email address: ";
    
           if(cin.peek() == '\n')
           {
               cin.ignore();
           }
    getline(cin,email_address);
    outfile << email_address << endl;
    
    cout <<"\nPlease enter New contact phone number: ";
    if(cin.peek() == '\n')
    {
         cin.ignore();
    }
    cin >> phone_number;
    outfile << phone_number << endl;
    
    outfile.close();
    outfile.clear();
}
