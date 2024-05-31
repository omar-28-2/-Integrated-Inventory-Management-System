#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

class Supplier;
class SparePart;

template <class T>
struct Node
{
    T data;
    Node *next;
    Node(T &newData) : data(newData), next(nullptr) {}
};
template <class T>
struct TreeNode
{
    T data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(T &newData) : data(newData), left(nullptr), right(nullptr) {}
};
class Supplier
{
private:
    string supplierName;
    int supplierCode;
    string address;
    string telephone;
    string email;
    // Forward declaration of SparePartNode
    struct SparePartNode;

    SparePartNode* suppliedParts; // Linked list of supplied spare parts
public:
    Supplier() : supplierName(""), supplierCode(0), address(""), telephone(""), email(""){}

    string getSupplierName() const { return supplierName; }
    int getSupplierCode() const { return supplierCode; }
    string getAddress() const { return address; }
    string getTelephone() const { return telephone; }
    string getEmail() const { return email; }

    void setSupplierName(const string& name) { supplierName = name; }
    void setSupplierCode(const int code) { supplierCode = code; }
    void setAddress(const string& addr) { address = addr; }
    void setTelephone(const string& phone) { telephone = phone; }
    void setEmail(const string& mail) { email = mail; }


    void getData()
    {
        cout << "Enter Supplier Name: ";
        cin >> supplierName;
        cout << "Enter Supplier Code: ";
        cin >> supplierCode;
        cout << "Enter Address: ";
        cin.ignore();
        getline(cin, address);
        cout << "Enter Telephone: ";
        cin >> telephone;
        cout << "Enter Email: ";
        cin >> email;
    }

    void displayData()
    {
        cout << "Supplier Name: " << supplierName << endl;
        cout << "Supplier Code: " << supplierCode << endl;
        cout << "Address: " << address << endl;
        cout << "Telephone: " << telephone << endl;
        cout << "Email: " << email << endl;

    }
    void addSuppliedPart(SparePart* part);
    void displaySuppliedParts();
};
class SparePart
{
private:
    string partName;
    int partNumber;
    double cost;
    int existingParts;
    // Forward declaration of SupplierNode
    struct SupplierNode;

    SupplierNode* suppliers; // Linked list of suppliers
public:
    SparePart() : partName(""), partNumber(0), cost(0.0),existingParts(0), suppliers(nullptr) {}

    string getPartName() const { return partName; }
    int getExistingParts() const { return existingParts; }
    double getCost() const { return cost; }
    int getPartNumber() const { return partNumber; }


    void setPartName(const string& partname) { partName = partname; }
    void setPartNumber(int number) { partNumber = number; }
    void setCost(double partCost) { cost = partCost; }
    void setExistingParts(int parts) { existingParts = parts; }

    // Function to get data
    void getData()
    {
        cout << "Enter the Part Name: ";
        cin >> partName;
        cout << "Enter the Part Number: ";
        cin >> partNumber;
        cout << "Enter the Cost: ";
        cin >> cost;
        cout << "Enter the number of existing parts: ";
        cin >> existingParts;
    }
    // Function to display data
    void displayData()
    {
        cout << "The Part Name is: " << partName << endl;
        cout << "The Part Number is: " << partNumber << endl;
        cout << "The Cost is: " << cost << endl;
        cout << "we have " << existingParts << endl;

    }

     void addSupplier(Supplier* supplier);

    // Function to display suppliers providing this spare part
    void displaySuppliers();
};

// Define SparePartNode struct after Supplier class definition


struct SparePart::SupplierNode {
    Supplier* data;
    SupplierNode* next;

    SupplierNode(Supplier* supplier) : data(supplier), next(nullptr) {}
};
/*time complexity
 best case is O(1)
 worst case is O(n)
*/
void SparePart::addSupplier(Supplier* supplier) {
    SupplierNode* newSupplierNode = new SupplierNode(supplier);
    if (!suppliers) {
        suppliers = newSupplierNode;
    } else {
        SupplierNode* temp = suppliers;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newSupplierNode;
    }
}
/*time complexity
 best case is O(1)
 worst case is O(n)
*/
void SparePart::displaySuppliers() {
    SupplierNode* temp = suppliers;
    cout << "Suppliers providing " << partName << " (Part Number: " << partNumber << "):" << endl;
    while (temp) {
        cout << temp->data->getSupplierName() << " (Code: " << temp->data->getSupplierCode() << ")" << endl;
        temp = temp->next;
    }
}

// Define SparePartNode struct after Supplier class definition
struct Supplier::SparePartNode {
    SparePart* data;
    SparePartNode* next;

    SparePartNode(SparePart* part) : data(part), next(nullptr) {}
};

/*time complexity
 best case is O(1)
 worst case is O(n)
*/
void Supplier::addSuppliedPart(SparePart* part) {
    SparePartNode* newPartNode = new SparePartNode(part);
    if (!suppliedParts) {
        suppliedParts = newPartNode;
    } else {
        SparePartNode* temp = suppliedParts;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newPartNode;
    }
}
/*time complexity
 best case is O(1)
 worst case is O(n)
*/
void Supplier::displaySuppliedParts() {
    SparePartNode* temp = suppliedParts;
    cout << "Spare parts supplied by " << supplierName << " (Code: " << supplierCode << "):" << endl;
    while (temp) {
        cout << temp->data->getPartName() << " (Part Number: " << temp->data->getPartNumber() << ")" << endl;
        temp = temp->next;
    }
}

/*
Time complexity for operations:
-------------------------------
- Pushing and popping interactions: O(1)
*/
class InteractionStack
{
    // InteractionStack class for managing user interactions

private:
    stack<string> interactions;
public:
    // Function to push a new interaction onto the stack
    void pushInteraction(string interaction)
    {
        interactions.push(interaction);
    }
    // Function to display the interaction history
    void displayInteractions()
{
    cout << "\nInteraction History:\n";
    stack<string> tempStack = interactions;
    while (!tempStack.empty())
    {
        cout << tempStack.top() << endl;
        tempStack.pop();
    }
}

};

/*
Time complexity for operations:
-------------------------------
- Insertion: Best Case O(log n), Worst Case O(n) (if the tree is unbalanced)
- Searching: Best Case O(log n), Worst Case O(n) (if the tree is unbalanced)
- Deletion:  Best Case O(log n), Worst Case O(n) (if the tree is unbalanced)
*/
class SparePartManager
{
private:
    TreeNode<SparePart> *sparePartsTree;
    queue<string> sparePartProcessingQueue;
public:
    SparePartManager() : sparePartsTree(nullptr) {}


    // Function to add a spare part to the spare parts tree
    bool addSparePart(SparePart part, vector<Supplier*>& partSuppliers) {
    if (searchSparePart(sparePartsTree, part.getPartNumber())) {
        cout << "Spare Part with Part Number " << part.getPartNumber() << " already exists." << endl;
        return false;
    }
    else {
        if (!sparePartsTree) {
            sparePartsTree = new TreeNode<SparePart>(part);
        }
        else {
            insertSparePart(sparePartsTree, part);
        }

        // Associate suppliers providing this spare part
        for (Supplier* supplier : partSuppliers) {
            part.addSupplier(supplier);
        }

        sparePartProcessingQueue.push("Spare Part " + to_string(part.getPartNumber()) + " added.");
        return true;
    }
}
    // Function to search for a spare part in the spare parts tree
    void searchSparePart(int partNumber)
    {
         // Search for the spare part in the spare parts tree
        TreeNode<SparePart> *result = searchSparePart(sparePartsTree, partNumber);
        if (result)
        {
            // If found, display the spare part data
            result->data.displayData();
        }
        else
        {
             // If not found, show a message
            cout << "Spare Part not found." << endl;
        }
    }
    // Function to delete a spare part from the spare parts tree
    void deleteSparePart(int partNumber)
    {
        // Initialize necessary pointers
        TreeNode<SparePart> *parent = nullptr;
        TreeNode<SparePart> *current = sparePartsTree;
        bool found = false;
        // Search for the spare part in the spare parts tree

        while (current)
        {
            if (partNumber == current->data.getPartNumber())
            {
                found = true;
                break;
            }
            else if (partNumber < current->data.getPartNumber())
            {
                parent = current;
                current = current->left;
            }
            else
            {
                parent = current;
                current = current->right;
            }
        }
        // Perform deletion based on different cases

        if (found)
        {
            if (!current->left && !current->right)
            {
                // Case 1: Node with no children
                if (!parent)
                {
                    delete sparePartsTree;
                    sparePartsTree = nullptr;
                }
                else if (parent->left == current)
                {
                    delete parent->left;
                    parent->left = nullptr;
                }
                else
                {
                    delete parent->right;
                    parent->right = nullptr;
                }
            }
            else if (!current->left || !current->right)
            {
                // Case 2: Node with one child
                TreeNode<SparePart> *child = current->left ? current->left : current->right;
                if (!parent)
                {
                    sparePartsTree = child;
                }
                else if (parent->left == current)
                {
                    parent->left = child;
                }
                else
                {
                    parent->right = child;
                }
                delete current;
            }
            else
            {
                // Case 3: Node with two children
                TreeNode<SparePart> *successorParent = current;
                TreeNode<SparePart> *successor = current->right;
                while (successor->left)
                {
                    successorParent = successor;
                    successor = successor->left;
                }
                current->data = successor->data;
                if (successorParent == current)
                {
                    successorParent->right = successor->right;
                }
                else
                {
                    successorParent->left = successor->right;
                }
                delete successor;
            }
            sparePartProcessingQueue.push("Spare Part " + to_string(partNumber) + " deleted.");
        }
        else
        {
            cout << "Spare Part not found." << endl;
        }
    }
    // Helper function to insert a spare part into the binary tree
    void insertSparePart(TreeNode<SparePart> *&node, SparePart &part)
    {
        // Recursive function to insert a spare part into the binary tree
        if (!node)
        {
            node = new TreeNode<SparePart>(part);
        }
        else
        {
            if (part.getPartNumber() < node->data.getPartNumber())
            {
                insertSparePart(node->left, part);
            }
            else
            {
                insertSparePart(node->right, part);
            }
        }
    }
    // Helper function to search for a spare part in the binary tree
    TreeNode<SparePart> *searchSparePart(TreeNode<SparePart> *node, int partNumber)
    {
        // Recursive function to insert a spare part into the binary tree
        if (!node || node->data.getPartNumber() == partNumber)
        {
            return node;
        }

        if (partNumber < node->data.getPartNumber())
        {
            return searchSparePart(node->left, partNumber);
        }
        else
        {
            return searchSparePart(node->right, partNumber);
        }
    }
    // Function to process spare part data
    void processSparePartData(string interaction)
    {
        sparePartProcessingQueue.push(interaction);
    }
    // Function to display spare part processing queue
    // Function to display spare part processing queue
    void displaySparePartProcessingQueue()
    {
        cout << "\nSpare Part Processing Queue:\n";
        queue<string> tempQueue = sparePartProcessingQueue;
        while (!tempQueue.empty())
        {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }
    void printAllSpareParts()
{
    if (sparePartsTree == nullptr)
    {
        cout << "No spare parts available.\n";
    }
    else
    {
        inorderTraversal(sparePartsTree);
    }
}

    // Helper function for inorder traversal
    void inorderTraversal(TreeNode<SparePart> *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            node->data.displayData(); // Assuming you have a displayData() function in the SparePart class
            inorderTraversal(node->right);
        }
    }
};
class SuppliersManager
{
private:
    TreeNode<Supplier> *suppliersTree;
    queue<string> supplierProcessingQueue;
public:
    SuppliersManager() : suppliersTree(nullptr) {}
    // Supplier binary search tree
/*
Time complexity for operations:
-------------------------------
- Insertion: Best Case O(log n), Worst Case O(n) (if the tree is unbalanced)
- Searching: Best Case O(log n), Worst Case O(n) (if the tree is unbalanced)
- Deletion:  Best Case O(log n), Worst Case O(n) (if the tree is unbalanced)
*/
    // Function to add a supplier to the binary tree with a unique identifier
    bool addSupplier(Supplier supplier, vector<SparePart*>& suppliedParts) {
    // Check if the supplier already exists
    if (searchSupplier(suppliersTree, supplier.getSupplierCode())) {
        cout << "Supplier with Supplier Code " << supplier.getSupplierCode() << " already exists." << endl;
        return false;
    }
    else {
        // If the tree is empty, create a new tree with the supplier
        if (!suppliersTree) {
            suppliersTree = new TreeNode<Supplier>(supplier);
        }
        else {
            // Insert the supplier into the binary tree
            insertSupplier(suppliersTree, supplier);
        }

        // Associate supplied parts with the supplier
        for (SparePart* part : suppliedParts) {
            supplier.addSuppliedPart(part);
        }

        // Push interaction onto processing queue
        supplierProcessingQueue.push("Supplier " + to_string(supplier.getSupplierCode()) + " added.");
        return true;
    }
}
    // Function to search for a supplier in the binary tree
    void searchSupplier(int supplierCode)
    {
         // Search for the supplier in the binary tree
        TreeNode<Supplier> *result = searchSupplier(suppliersTree, supplierCode);
        if (result)
        {
            // If found, display the supplier data
            result->data.displayData();
        }
        else
        {
            // If not found, show a message
            cout << "Supplier not found." << endl;
        }
    }

    // Function to delete a supplier from the binary tree
    void deleteSupplier(int supplierCode)
    {
        // Initialize necessary pointers
        TreeNode<Supplier> *parent = nullptr;
        TreeNode<Supplier> *current = suppliersTree;
        bool found = false;

        // Search for the supplier in the binary tree
        while (current)
        {
            if (supplierCode == current->data.getSupplierCode())
            {
                found = true;
                break;
            }
            else if (supplierCode < current->data.getSupplierCode())
            {
                parent = current;
                current = current->left;
            }
            else
            {
                parent = current;
                current = current->right;
            }
        }
        // Perform deletion based on different cases
        if (found)
        {
            if (!current->left && !current->right)
            {
                // Case 1: Node with no children
                if (!parent)
                {
                    delete suppliersTree;
                    suppliersTree = nullptr;
                }
                else if (parent->left == current)
                {
                    delete parent->left;
                    parent->left = nullptr;
                }
                else
                {
                    delete parent->right;
                    parent->right = nullptr;
                }
            }
            else if (!current->left || !current->right)
            {
                // Case 2: Node with one child
                TreeNode<Supplier> *child = current->left ? current->left : current->right;
                if (!parent)
                {
                    suppliersTree = child;
                }
                else if (parent->left == current)
                {
                    parent->left = child;
                }
                else
                {
                    parent->right = child;
                }
                delete current;
            }
            else
            {
                // Case 3: Node with two children
                TreeNode<Supplier> *successorParent = current;
                TreeNode<Supplier> *successor = current->right;
                while (successor->left)
                {
                    successorParent = successor;
                    successor = successor->left;
                }
                current->data = successor->data;
                if (successorParent == current)
                {
                    successorParent->right = successor->right;
                }
                else
                {
                    successorParent->left = successor->right;
                }
                delete successor;
            }
            // Update processing queue accordingly
            supplierProcessingQueue.push("Supplier " + to_string(supplierCode) + " deleted.");
        }
        else
        {
            cout << "Supplier not found." << endl;
        }
    }
    // Helper function to insert a supplier into the binary tree
    void insertSupplier(TreeNode<Supplier> *&node, Supplier &supplier)
    {
        // Recursive function to insert a supplier into the binary tree
        if (!node)
        {
            node = new TreeNode<Supplier>(supplier);
        }
        else
        {
            if (supplier.getSupplierCode() < node->data.getSupplierCode())
            {
                insertSupplier(node->left, supplier);
            }
            else
            {
                insertSupplier(node->right, supplier);
            }
        }
    }

    // Helper function to search for a supplier in the binary tree
    TreeNode<Supplier> *searchSupplier(TreeNode<Supplier> *node, int supplierCode)
    {
        // Recursive function to search for a supplier in the binary tree
        if (!node || node->data.getSupplierCode() == supplierCode)
        {
            return node;
        }

        if (supplierCode < node->data.getSupplierCode())
        {
            return searchSupplier(node->left, supplierCode);
        }
        else
        {
            return searchSupplier(node->right, supplierCode);
        }
    }
    // Function to process supplier data
    void processSupplierData(string interaction)
    {
        supplierProcessingQueue.push(interaction);
    }
    // Function to display supplier processing queue
    void displaySupplierProcessingQueue()
    {
        cout << "\nSupplier Processing Queue:\n";
        queue<string> tempQueue = supplierProcessingQueue;
        while (!tempQueue.empty())
        {
            cout << tempQueue.front() << endl;
            tempQueue.pop();
        }
    }
    // Function to print all suppliers
    void printAllSuppliers()
    {
        if (suppliersTree)
        {
            cout << "All Suppliers:\n";
            inorderTraversal(suppliersTree);
        }
        else
        {
            cout << "No suppliers found." << endl;
        }
    }
    // Helper function for inorder traversal
    void inorderTraversal(TreeNode<Supplier> *node)
    {
        if (node != nullptr)
        {
            inorderTraversal(node->left);
            node->data.displayData();
            inorderTraversal(node->right);
        }
    }
};

int main() {
    int choice;
    SparePart myPart;
    Supplier mySupplier;
    SparePartManager sparePartManager;
    SuppliersManager suppliersManager;
    InteractionStack interactionStack;

    do {
        cout << "--------------> MENU <------------\n"
             << "1. Spare Parts\n"
             << "2. Suppliers\n"
             << "3. Search Spare Part\n"
             << "4. Search Supplier\n"
             << "5. Display Interaction History\n"
             << "0. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int sparePartOption;
                cout << "1. Print \n"
                     << "2. Add \n"
                     << "3. Modify \n"
                     << "4. Delete \n"
                     << "0. Back \n"
                     << "Enter your choice: ";
                cin >> sparePartOption;

                switch (sparePartOption) {
                    case 1:
                        sparePartManager.printAllSpareParts();
                        break;
                    case 2:{
                            int numSuppliers;
                            cout << "Enter the number of suppliers providing this spare part: ";
                            cin >> numSuppliers;
                            vector<Supplier*> partSuppliers;
                            for (int i = 0; i < numSuppliers; ++i) {
                            Supplier* newSupplier = new Supplier();
                            cout << "Enter details for Supplier " << i + 1 << ":\n";
                            newSupplier->getData(); // Assuming a function to get supplier details
                            partSuppliers.push_back(newSupplier);
                           }
                         // Get spare part details
                         myPart.getData();
                         // Add spare part and associated suppliers
                         sparePartManager.addSparePart(myPart, partSuppliers);
                         interactionStack.pushInteraction("User added a spare part " + to_string(myPart.getPartNumber()));
                         break;
                           }
                    case 3: {
                        int modifyOption;
                        cout << "Modify Spare Part Data:\n"
                             << "1. Part Name\n"
                             << "2. Part Number\n"
                             << "3. Cost\n"
                             << "4. Existing Parts Count\n"
                             << "Enter your choice: ";
                        cin >> modifyOption;

                        switch (modifyOption) {
                            case 1: {
                                cout << "Enter new part name: ";
                                string newName;
                                cin >> newName;
                                myPart.setPartName(newName);
                                interactionStack.pushInteraction("User modified Part Name of Spare Part number " + to_string(myPart.getPartNumber()));
                                break;
                            }
                            case 2: {
                                cout << "Enter new part number: ";
                                int newNumber;
                                cin >> newNumber;
                                myPart.setPartNumber(newNumber);
                                interactionStack.pushInteraction("User modified Part Number of Spare Part number " + to_string(myPart.getPartNumber()));
                                break;
                            }
                            case 3: {
                                cout << "Enter new cost: ";
                                double newCost;
                                cin >> newCost;
                                myPart.setCost(newCost);
                                interactionStack.pushInteraction("User modified Cost of Spare Part number " + to_string(myPart.getPartNumber()));
                                break;
                            }
                            case 4: {
                                cout << "Enter new existing parts count: ";
                                int newExistingParts;
                                cin >> newExistingParts;
                                myPart.setExistingParts(newExistingParts);
                                interactionStack.pushInteraction("User modified Existing Parts Count of Spare Part number " + to_string(myPart.getPartNumber()));
                                break;
                            }
                            default:
                                cout << "Invalid choice. Please try again.\n";
                                break;
                        }
                        break;
                    }
                    case 4: {
                        int partNumberToDelete;
                        cout << "Enter Part Number to delete: ";
                        cin >> partNumberToDelete;
                        sparePartManager.deleteSparePart(partNumberToDelete);
                        interactionStack.pushInteraction("User deleted Spare Part number " + to_string(partNumberToDelete));
                        break;
                    }
                    case 0:
                        break; // Back to the previous menu
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
                break;
            }
            case 2: {
                int supplierOption;
                cout << "1. print\n"
                     << "2. Add\n"
                     << "3. Modify\n"
                     << "4. Delete\n"
                     << "0. Back\n"
                     << "Enter your choice: ";
                cin >> supplierOption;

                switch (supplierOption) {
                    case 1:
                        suppliersManager.printAllSuppliers();
                        break;
                    case 2: {
                          int numParts;
                          cout << "Enter the number of parts supplied by the new supplier: ";
                          cin >> numParts;

                          vector<SparePart*> suppliedParts;
                          for (int i = 0; i < numParts; ++i) {
                          SparePart* newPart = new SparePart();
                          cout << "Enter details for Part " << i + 1 << ":\n";
                          newPart->getData(); // Assuming a function to get part details
                          suppliedParts.push_back(newPart);
                          }
                          // Get supplier details
                          mySupplier.getData();
                          // Add supplier and associated parts
                         suppliersManager.addSupplier(mySupplier, suppliedParts);
                         interactionStack.pushInteraction("User added supplier " + to_string(mySupplier.getSupplierCode()));
                         break;
                         }
                    case 3: {
                        int modifySupplierOption;
                        cout << "Modify Supplier Data:\n"
                             << "1. Supplier Name\n"
                             << "2. Supplier Code\n"
                             << "3. Address\n"
                             << "4. Telephone\n"
                             << "5. Email\n"
                             << "Enter your choice: ";
                        cin >> modifySupplierOption;

                        switch (modifySupplierOption) {
                            case 1: {
                                cout << "Enter new supplier name: ";
                                string newName;
                                cin >> newName;
                                mySupplier.setSupplierName(newName);
                                interactionStack.pushInteraction("User modified Supplier Name of Supplier " + to_string(mySupplier.getSupplierCode()));
                                break;
                            }
                            case 2: {
                                cout << "Enter new supplier code: ";
                                int newCode;
                                cin >> newCode;
                                mySupplier.setSupplierCode(newCode);
                                interactionStack.pushInteraction("User modified Supplier Code of Supplier " + to_string(mySupplier.getSupplierCode()));
                                break;
                            }
                            case 3: {
                                cout << "Enter new address: ";
                                string newAddress;
                                cin.ignore();
                                getline(cin, newAddress);
                                mySupplier.setAddress(newAddress);
                                interactionStack.pushInteraction("User modified Address of Supplier " + to_string(mySupplier.getSupplierCode()));
                                break;
                            }
                            case 4: {
                                cout << "Enter new telephone: ";
                                string newTelephone;
                                cin >> newTelephone;
                                mySupplier.setTelephone(newTelephone);
                                interactionStack.pushInteraction("User modified Telephone of Supplier " + to_string(mySupplier.getSupplierCode()));
                                break;
                            }
                            case 5: {
                                cout << "Enter new email: ";
                                string newEmail;
                                cin >> newEmail;
                                mySupplier.setEmail(newEmail);
                                interactionStack.pushInteraction("User modified Email of Supplier " + to_string(mySupplier.getSupplierCode()));
                                break;
                            }
                            default:
                                cout << "Invalid choice. Please try again.\n";
                                break;
                        }
                        break;
                    }
                    case 4: {
                        int supplierCodeToDelete;
                        cout << "Enter Supplier Code to delete: ";
                        cin >> supplierCodeToDelete;
                        suppliersManager.deleteSupplier(supplierCodeToDelete);
                        interactionStack.pushInteraction("User deleted Supplier " + to_string(supplierCodeToDelete));
                        break;
                    }
                    case 0:
                        break; // Back to the previous menu
                    default:
                        cout << "Invalid choice. Please try again.\n";
                }
                break;
            }
            case 3: {
                cout << "\nSearch Spare Part:\n";
                int searchPartNumber;
                cout << "Enter Part Number to search: ";
                cin >> searchPartNumber;
                sparePartManager.searchSparePart(searchPartNumber);
                break;
            }
            case 4: {
                cout << "\nSearch Supplier:\n";
                int searchSupplierCode;
                cout << "Enter Supplier Code to search: ";
                cin >> searchSupplierCode;
                suppliersManager.searchSupplier(searchSupplierCode);
                break;
            }
            case 5: {
                interactionStack.displayInteractions();
                break;
            }
            case 0: {
                cout << "Exiting the program. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
            }
        }
    } while (choice != 0);

    return 0;
}
