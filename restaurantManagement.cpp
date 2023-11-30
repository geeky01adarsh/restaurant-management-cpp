#include <bits/stdc++.h>

using namespace std;

int previewOrder(unordered_map<string, pair<int, int>> orders)
{
    cout << "You have ordered:" << endl;
    cout << "   dish    X    quantity    ---    price(each)" << endl;

    int totalAmount = 0;
    for (auto i : orders)
    {
        string dish = i.first;
        int price = i.second.first;
        int quantity = i.second.second;
        cout << dish << "   X   " << quantity << "   ----   " << price << endl;
        totalAmount += quantity * price;
    }
    return totalAmount;
}

unordered_map<string, pair<int, int>> getResturantOrders()
{
introMsg:
    // Printing instructions
    cout << "Press any key to start your order!" << endl;
    cout << "Press (a) for veg items!" << endl;
    cout << "Press (b) for non-veg items!" << endl;
    cout << "Press (p) for preview and (x) for existing anytime!" << endl;

    // declaring variables
    char startSymbol, foodType, exitConfirmation, order, quantity;
    unordered_map<string, pair<int, int>> orders; // items, price, items
    bool preview = false;

// preview the orders
previewOrders:
    if (preview)
    {
        preview = false;
        previewOrder(orders);
    previewExit:
        cout << "Do you want anything else (y) or (n)?" << endl;
        cin >> exitConfirmation;
        if (exitConfirmation == 'y' || exitConfirmation == 'Y')
        {
            goto introMsg;
        }
        else if (exitConfirmation == 'n' || exitConfirmation == 'N')
        {
            return orders;
        }
        else
        {
            goto previewExit;
        }
    }

// start taking orders
startRestro:

    cin >> startSymbol;
    if (startSymbol == 'x' || startSymbol == 'X')
    {
        cout << "Press (p) for previewing, (y) to exit and any other key to continue!!!";
        cin >> exitConfirmation;
        if (exitConfirmation == 'y' || exitConfirmation == 'Y')
            return orders;
        else if (exitConfirmation == 'p' || exitConfirmation == 'P')
        {
            preview = true;
            goto previewOrders;
        }
        else
            goto startRestro;
    }

// get food choice
foodTypeChoice:
    cout << "Enter your choice:" << endl;
    cout << "(A) veg            (B) non-veg" << endl;
    cin >> foodType;
foodOrders:
    if (foodType == 'x' || foodType == 'X')
    {
        cout << "Are you sure you want to exit (y) or (n)?" << endl;
        cin >> exitConfirmation;
        if (exitConfirmation == 'y' || exitConfirmation == 'Y')
            return orders;

        else
            goto foodTypeChoice;
    }

    // veg food order
    else if (foodType == 'a' || foodType == 'A')
    {
    vegFood:
        cout << "Press (1), (2), (3), (4), (5) for selecting food!" << endl;
        cout << "Press (c) to change food type!" << endl;
        cout << "Press (p) to preview or (x) to exit anytime!" << endl;
        cout << "Food Items:" << endl;
        cout << "(1) Matar Paneer --- Rs. 150" << endl;
        cout << "(2) Aaloo Paratha --- Rs. 25" << endl;
        cout << "(3) Butter Roti --- Rs. 15" << endl;
        cout << "(4) Pulao --- Rs. 120" << endl;
        cout << "(5) Paneer Roll --- Rs. 100" << endl;

        cin >> order;

        if (order == 'x' || order == 'X')
        {
            foodType = 'X';
            goto foodOrders;
        }
        else if (order == 'c' || order == 'C')
        {
            cout << "Changing food category" << endl;
            goto foodTypeChoice;
        }
        else if (order == 'p' || order == 'P')
        {
            preview = true;
            goto previewOrders;
        }
        else if (order >= '1' || order <= '5')
        {
            cout << "Now please choose the quantity" << endl;
        }
        else
        {
            cout << "You entered a wrong key!\nPlease try again!\n";
        }

    vegQuantity:
        cout << "Please enter the quantity(1-9)!" << endl;
        cin >> quantity;

        int item = 0;
        if (quantity >= '1' || quantity <= '9')
            item = quantity - '0';
        else
        {
            cout << "You have entered a wrong quantity, please try again!!!" << endl;
            goto vegQuantity;
        }

        if (order == '1')
        {
            if (orders.count("Matar Paneer"))
            {
                int prevCount = orders["Matar Paneer"].second;
                orders["Matar Paneer"] = {150, prevCount + item};
            }
            else
            {
                orders["Matar Paneer"] = {150, item};
            }
        }
        else if (order == '2')
        {
            if (orders.count("Aaloo Paratha"))
            {
                int prevCount = orders["Aaloo Paratha"].second;
                orders["Aaloo Paratha"] = {25, prevCount + item};
            }
            else
            {
                orders["Aaloo Paratha"] = {25, item};
            }
        }
        else if (order == '3')
        {
            if (orders.count("Butter Roti"))
            {
                int prevCount = orders["Aaloo Paratha"].second;
                orders["Butter Roti"] = {15, prevCount + item};
            }
            else
            {
                orders["Butter Roti"] = {15, item};
            }
        }
        else if (order == '4')
        {
            if (orders.count("Pulao"))
            {
                int prevCount = orders["Pulao"].second;
                orders["Pulao"] = {120, prevCount + item};
            }
            else
            {
                orders["Pulao"] = {120, item};
            }
        }
        else if (order == '5')
        {
            if (orders.count("Paneer Roll"))
            {
                int prevCount = orders["Paneer Roll"].second;
                orders["Paneer Roll"] = {150, prevCount + item};
            }
            else
            {
                orders["Paneer Roll"] = {150, item};
            }
        }

        cout << "Press any key to order more, (p) for preview, or (x) to wrap up!!!" << endl;
        cin >> order;
        if (order == 'x' || order == 'X')
        {
            foodType = 'X';
            goto foodOrders;
        }
        else if (order == 'p' || order == 'P')
        {
            preview = true;
            goto previewOrders;
        }
        else
            goto vegFood;
    }

    // non-veg food order
    else if (foodType == 'b' || foodType == 'B')
    {
    nonVegFood:
        cout << "Press (1), (2), (3), (4), (5) for selecting food!" << endl;
        cout << "Press (c) to change food type!" << endl;
        cout << "Press (x) to exit anytime!" << endl;
        cout << "Food Items:" << endl;
        cout << "(1) Butter Chicken --- Rs. 250" << endl;
        cout << "(2) Boiled Egg --- Rs. 25" << endl;
        cout << "(3) Omelette(2 eggs) --- Rs. 80" << endl;
        cout << "(4) Chicken Briyani --- Rs. 180" << endl;
        cout << "(5) Egg Roll(2 eggs) --- Rs. 100" << endl;

        cin >> order;

        if (order == 'x' || order == 'X')
        {
            foodType = 'X';
            goto foodOrders;
        }
        else if (order == 'c' || order == 'C')
        {
            cout << "Changing food category" << endl;
            goto foodTypeChoice;
        }
        else if (order == 'p' || order == 'P')
        {
            preview = true;
            goto previewOrders;
        }
        else if (order >= '1' || order <= '5')
        {
            cout << "Now please choose the quantity" << endl;
        }
        else
        {
            cout << "You entered a wrong key!\nPlease try again!\n";
        }

    nonVegQuantity:
        cout << "Please enter the quantity(1-9)!" << endl;
        cin >> quantity;

        int item = 0;
        if (quantity >= '1' || quantity <= '9')
            item = quantity - '0';
        else
        {
            cout << "You have entered a wrong quantity, please try again!!!" << endl;
            goto nonVegQuantity;
        }

        if (order == '1')
        {
            if (orders.count("Butter Chicken"))
            {
                int prevCount = orders["Butter Chicken"].second;
                orders["Butter Chicken"] = {250, prevCount+item};
            }
            else
            {
                orders["Butter Chicken"] = {250, item};
            }
        }
        else if (order == '2')
        {
            if (orders.count("Boiled Egg"))
            {
                int prevCount = orders["Boiled Egg"].second;
                orders["Boiled Egg"] = {25, item};
            }
            else
            {
                orders["Boiled Egg"] = {25, item};
            }
        }
        else if (order == '3')
        {
            if (orders.count("Omelette(2 eggs)"))
            {
                int prevCount = orders["Omelette(2 eggs)"].second;
                orders["Omelette(2 eggs)"] = {80, item};
            }
            else
            {
                orders["Omelette(2 eggs)"] = {80, item};
            }
        }
        else if (order == '4')
        {
            if (orders.count("Chicken Briyani"))
            {
                int prevCount = orders["Chicken Briyani"].second;
                orders["Chicken Briyani"] = {180, item};
            }
            else
            {
                orders["Chicken Briyani"] = {180, item};
            }
        }
        else if (order == '5')
        {
            if (orders.count("Egg Roll(2 eggs)"))
            {
                int prevCount = orders["Egg Roll(2 eggs)"].second;
                orders["Egg Roll(2 eggs)"] = {100, item};
            }
            else
            {
                orders["Egg Roll(2 eggs)"] = {100, item};
            }
        }
        cout << "Press any key to order more, (p) for preview, or (x) to wrap up!!!" << endl;
        cin >> order;
        if (order == 'x' || order == 'X')
        {
            foodType = 'X';
            goto foodOrders;
        }
        else if (order == 'p' || order == 'P')
        {
            preview = true;
            goto previewOrders;
        }
        else
            goto nonVegFood;
    }

    else
    {
        cout << "You have entered a wrong key!!!" << endl;
        goto foodTypeChoice;
    }
    return orders;
}

// main function
int main()
{
    cout << "----------------Welcome to our Resturant---------------------" << endl;
    cout << "------------------Please place your order-------------------" << endl;
    unordered_map<string, pair<int, int>> orders = getResturantOrders();
    if (orders.empty())
    {
        cout << "You have not ordered anything!" << endl;
    }
    else
    {
        int totalAmount = previewOrder(orders);
        cout << "You total amount including 10 percent taxes: " << totalAmount + (0.1 * totalAmount) << endl;
    }
    cout << "Thank you for visiting us!" << endl;
    cout << "Have a nice day!" << endl;
    return 0;
}
