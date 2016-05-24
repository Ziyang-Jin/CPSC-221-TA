// File:        ccqueue.h
// Author:      Geoffrey Tien
// Date:        2016-05-21
// Description: Definition of a customer complaint queue class for CPSC 221 assignment 2

#ifndef _CCQUEUE_H_
#define _CCQUEUE_H_

#include <algorithm> // needed for min function
#include <sstream>
#include <string>

#include "linkedlist.h"
#include "ticket.h"

using namespace std;

class CCQueue
{
  private:
    LinkedList<Ticket> tickets;  // collection of ticket objects
    unsigned int maxticketid;    // current largest-valued ticketid. Used to generate new tickets to insert

  public:
    // default constructor
    // maxticketid begins at 0
    // note that tickets does not need to be re-declared
    CCQueue();

    // MUTATORS
    
    // enqueues a new ticket at the back of the ticket queue and returns true
    // ticketid is assigned automatically as 1+maxticketid if enqueueing is possible
    // does not enqueue and returns false if either parameter is empty string
    // POST:  new ticket with supplied parameters is added to back of tickets,
    //        maxticketid is incremented
    // PARAM: customer and complaint fields to pass to Ticket constructor
    bool Add(string customer, string complaint);

    // removes and returns an item from the front of the ticket queue
    // throws a logic_error if the ticket queue is empty
    // POST:  first item of the ticket queue is removed
    Ticket Service();

    // moves an item towards the front of the queue by 1 position and returns true
    // returns false if supplied index is 0 (first item) or outside the list boundaries
    // POST:  DLinkedList items at position and position-1 swap spots in the list
    // PARAM: initial index of item to move up
    bool MoveUp(int index);

    // moves an item towards the back of the queue by 1 position and returns true
    // returns false if supplied index is the last item or outside the list boundaries
    // POST:  DLinkedList items at position and position+1 swap spots in the list
    // PARAM: initial index of item to move down
    bool MoveDown(int index);

    // ACCESSORS
    
    // returns the number of tickets
    int Size() const;

    // returns a formatted string with the ticket queue contents
    // You may use this function to check the contents of your queue
    // You do not need to copy this into your .cpp file
    string PrintStatus() const
    {
      string complainttext;
      ostringstream output;
      output << "Ticket queue contains " << tickets.Size() << " open tickets.\n";
      output << "Position\tTicket ID\tCustomer\tShort description\n";
      output << "-----------------------------------------------------------------------\n";
      for (int i = 0; i < tickets.Size(); i++)
      {
        complainttext = tickets.ElementAt(i).GetComplaint();
        output << i+1 << "\t\t" << tickets.ElementAt(i).GetID() << "\t\t"
               << tickets.ElementAt(i).GetCustomer() << "\t" << complainttext.substr(0, min((int)20, (int)complainttext.length())) << "...\n";
      }
      return output.str();
    };
};

#endif
