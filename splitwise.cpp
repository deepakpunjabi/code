#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;

class Person;
class Group;
class Bill;
class Application;

class Person
{
    int id;
    string name;

  public:
    Person(int id, string name)
    {
        this->id = id;
        this->name = name;
    }

    void addPerson(int id, string name)
    {
        Person(id, name);
    }

    int getId()
    {
        return id;
    }

    string getName()
    {
        return name;
    }
};

class Group
{
    int id;
    set<int> members;

  public:
    Group(vector<Person> p)
    {
        for (auto i : p)
        {
            members.insert(i.getId());
        }
    }

    bool isValid(vector<Person> p)
    {
        for (auto i : p)
        {
            int pid = i.getId();
            if (members.find(pid) == members.end())
            {
                return false;
            }
        }
        return true;
    }
};

class Bill
{
    int id;
    int amount; // assuming integer total amounts
    map<int, int> memberShare;
    vector<Person> p;
    vector<int> pshare;

  public:
    Bill(int id, int amount){
        this->id = id;
        this->amount = amount;
    }

    void registerBill(int total, vector<pair<Person, int>> shares, Group g)
    {
        amount = 0;

        //check persons against the group
        for (auto share : shares)
        {

            Person tmpPerson = share.first;
            int tmpShare = share.second;

            // memberShare.emplace(tmpPerson.getId(), 0);
            

            p.push_back(tmpPerson);
            pshare.push_back(tmpShare);

            amount += tmpShare;
        }



        // input validation: check total against given shares
        if (total != amount)
        {
            cout << "ERROR --> Shares does not sum to Total amount" << endl;
            return;
        }

        // input validation: check persons against the registered group
        if (!g.isValid(p))
        {
            cout << "ERROR --> One of more member of shares does not belong to the group" << endl;
            return;
        }

        // calculate per person amount to be paid
        int sizeOfGroup = p.size();
        float average = total / sizeOfGroup;
        int finalShare;

        for (int it = 0; it < sizeOfGroup; ++it)
        {
            finalShare = pshare[it] - average;
            memberShare[p[0].getId()] = finalShare;
        }
    }

    void calculateShare();

    // void registerBill(int total, vector<pair<Person, float>> shares, Group g)
    // {
    // }

    void printShares()
    {
        cout << "Person"
             << "\t"
             << "Share" << endl;

        // TODO:  x has to give/take amount.
        for (auto i : memberShare)
        {
            cout << p[i.first].getName() << "\t"
                 << i.second << endl;
        }
    }
};

// take input into driver -- main
// do application logic in application class

int main()
{
    vector<Person> persons;

    // register members
    Person p1(1, "user1");
    persons.push_back(p1);
    Person p2(2, "user2");
    persons.push_back(p2);
    Person p3(3, "user3");
    persons.push_back(p3);

    // register group
    Group g1(persons);

    // test case 1
    int total = 200;
    vector<pair<Person, int>> bill1Shares;
    bill1Shares.push_back(make_pair(p2,150));
    bill1Shares.push_back(make_pair(p3,50));
    bill1Shares.push_back(make_pair(p1,0));
    // add a bill
    Bill b1(1,total);
    // b1.registerBill(total, bill1Shares, g1);
    b1.registerBill(total, bill1Shares, g1);
    b1.printShares();
    return 0;
}
