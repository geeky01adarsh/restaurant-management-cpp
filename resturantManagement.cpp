    #include <iostream>
    #include <unordered_map>
    #include <pair>

    using namespace std;

    void preview(unordered_map<string, pair<int, int>>){

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
        char startSymbol, foodType, exitConformation, order, quantity;
        unordered_map<string, pair<int, int>> orders;
        bool preview = false;


    // preview the orders
    previewOrders:
    if()

    // start taking orders
    startRestro:

        cin >> startSymbol;
        if (startSymbol == 'x' || startSymbol == 'X')
        {
            cout << "Press (p) for previewing, (y) to exit and any other key to continue!!!";
            cin >> exitConformation;
            if (exitConformation == 'y' || exitConformation == 'Y')
                return orders;
            else if (preview)
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
            cin >> exitConformation;
            if (exitConformation == 'y' || exitConformation == 'Y')
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
            cout << "Press (x) to exit anytime!" << endl;
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
            else if (order >= '1' || order <= '5')
            {
                cout << "Thank you! \nNow please choose the quantity" << endl;
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
                    int prevCount = order["Matar Paneer"].second;
                    order["Matar Paneer"] = {150, prevCount+item};
                }
                else
                {
                    order["Matar Paneer"] ={150, item};
                }
            }
            else if (order == '2')
            {
                if (orders.count("Aaloo Paratha"))
                {
                    int prevCount = order["Aaloo Paratha"].second;
                    order["Aaloo Paratha"] = {25,  prevCount+item};
                }
                else
                {
                    order["Aaloo Paratha"] = {25, item};
                }
            }
            else if (order == '3')
            {
                if (orders.count("Butter Roti"))
                {
                    int prevCount = order["Aaloo Paratha"].second;
                    order["Butter Roti"] = {15, prevCount+item};
                }
                else
                {
                    order["Butter Roti"] = {15,item};
                }
            }
            else if (order == '4')
            {
                if (orders.count("Pulao"))
                {
                    int prevCount = order["Pulao"].second;
                    order["Pulao"] += {120, prevCount+item};
                }
                else
                {
                    order["Pulao"] = {120, item};
                }
            }
            else if (order == '5')
            {
                if (orders.count("Paneer Roll"))
                {
                    int prevCount = order["Paneer Roll"].second;
                    order["Paneer Roll"] += {150, prevCount+item};
                }
                else
                {
                    order["Paneer Roll"] = 150 * item;
                }
            }

            cout << "Press any key to order more or (x) to wrap up!!!" << endl;
            cin >> order;
            if (order == 'x' || order == 'X')
            {
                foodType = 'X';
                goto foodOrders;
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
            else if (order >= '1' || order <= '5')
            {
                cout << "Thank you! \nNow please choose the quantity" << endl;
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
                goto nonVegQuantity;
            }

            if (order == '1')
            {
                if (orders.count("Matar Paneer"))
                {
                    order["Matar Paneer"] += 150 * item;
                }
                else
                {
                    order["Matar Paneer"] = 150 * item;
                }
            }
            else if (order == '2')
            {
                if (orders.count("Aaloo Paratha"))
                {
                    order["Aaloo Paratha"] += 25 * item;
                }
                else
                {
                    order["Aaloo Paratha"] = 25 * item;
                }
            }
            else if (order == '3')
            {
                if (orders.count("Butter Roti"))
                {
                    order["Butter Roti"] += 15 * item;
                }
                else
                {
                    order["Butter Roti"] = 15 * item;
                }
            }
            else if (order == '4')
            {
                if (orders.count("Pulao"))
                {
                    order["Pulao"] += 120 * item;
                }
                else
                {
                    order["Pulao"] = 120 * item;
                }
            }
            else if (order == '5')
            {
                if (orders.count("Paneer Roll"))
                {
                    order["Paneer Roll"] += 150 * item;
                }
                else
                {
                    order["Paneer Roll"] = 150 * item;
                }
            }
            cout << "Press any key to order more or (x) to wrap up!!!" << endl;
            cin >> order;
            if (order == 'x' || order == 'X')
            {
                foodType = 'X';
                goto foodOrders;
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
        unordered_map<string, int> orders = getResturantOrders();
        if (orders.empty())
        {
            cout << "You have not ordered anything!" << endl;
            cout << "Thank you for visiting us!" << endl;
            cout << "Have a nice day!" << endl;
            return 0;
        }
    }