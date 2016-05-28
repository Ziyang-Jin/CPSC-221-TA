#include <string>
#include "ccqueue.h"
#include "ticket.h"
#include "linkedlist.h"

CCQueue::CCQueue() : maxticketid(0) {}

bool CCQueue::Add(string customer, string complaint) {
    if(customer == "" || complaint == "") return false;
    Ticket t(++maxticketid, customer, complaint);
    tickets.InsertBack(t);
    return true;
}

Ticket CCQueue::Service() {
    if(tickets.IsEmpty()) throw logic_error("empty ticket queue");
    return tickets.RemoveAt(0);
}

bool CCQueue::MoveUp(int index) {
    if(index == 0 || index >= tickets.Size()) return false;
    tickets.InsertAt(tickets.RemoveAt(index), index-1);
    return true;
}

bool CCQueue::MoveDown(int index) {
    if(index >= tickets.Size()-1) return false;
    tickets.InsertAt(tickets.RemoveAt(index), index+1);
    return true;
}

int CCQueue::Size() const { return tickets.Size(); }
