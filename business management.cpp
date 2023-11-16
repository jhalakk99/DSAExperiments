#include <iostream>
#include <queue>
#include <string>

// Define a struct to represent a customer inquiry with a name and priority.
struct CustomerInquiry {
    std::string name;
    int priority;

    CustomerInquiry(std::string n, int p) : name(std::move(n)), priority(p) {}
};

// Custom comparison function for the priority queue.
struct InquiryComparator {
    bool operator()(const CustomerInquiry& inquiry1, const CustomerInquiry& inquiry2) const {
        // Higher priority inquiries come first.
        return inquiry1.priority < inquiry2.priority;
    }
};

int main() {
    std::priority_queue<CustomerInquiry, std::vector<CustomerInquiry>, InquiryComparator> inquiryQueue;

    int numInquiries;

    std::cout << "Enter the number of customer inquiries: ";
    std::cin >> numInquiries;

    for (int i = 0; i < numInquiries; ++i) {
        std::string customerName;
        int inquiryPriority;

        std::cout << "Enter the name of the customer: ";
        std::cin.ignore();
        std::getline(std::cin, customerName);

        std::cout << "Enter the priority of the inquiry (1 for high, 2 for medium, 3 for low): ";
        std::cin >> inquiryPriority;

        inquiryQueue.push(CustomerInquiry(customerName, inquiryPriority));
    }

    // Process inquiries in order of their priority.
    std::cout << "Processing customer inquiries based on priority:\n";
    while (!inquiryQueue.empty()) {
        CustomerInquiry inquiry = inquiryQueue.top();
        inquiryQueue.pop();
        std::cout << "Processing inquiry from " << inquiry.name << " (Priority: " << inquiry.priority << ")\n";
        // You can add your own business logic here to handle the inquiries.
    }

    return 0;
}