#include <iostream>
#include <string>
#include <array>


namespace cars
{
    //**************************************************** CAR CLASS ****************************************************************/
    
    
    class Car
    {
        private:

            static int instance_counter;
            friend void getInstanceCount(const Car &c);
             
           
        protected:
            
            std::string trading_mark_{"None"};
            int cyllinders_number_{0};
            int power_{0};
            int get_instance_counter() const;
            int object_ID_{0};
                        

        public:

            // Default constructor
            Car() 
            {
                this->instance_counter++;
                this->object_ID_ = this->instance_counter;
                std::cout << "Default vehicle constructor is working. "<< std::endl;
                std::cout << "Vehicle created. Instance counter of vehicles  is: " << this->instance_counter << std::endl;
            }
            // Constructor with params
            Car(std::string mark, int cyll, int power):Car()
            {
              this->trading_mark_ = mark;
              this->cyllinders_number_ = cyll;
              this->power_ = power;
              std::cout<<"Constructor with parameters is working!"<<std::endl;
              
            }
            // Copy constructor
            Car(const Car &C):Car()
            {
               this->trading_mark_ = C.trading_mark_;
               this->cyllinders_number_ = C.cyllinders_number_;
               this->power_ = C.power_;
               std::cout<<"Copy constructor is working!"<<std::endl;
            }
            // Destructor  
            ~Car()
            {
                this->instance_counter--;
                std::cout << "Car destroyed. Instance counter of all cars is: " << this->instance_counter << std::endl;
            }
            //Setters
            void set_TradeMark(std::string trade_mark);
            void set_CyllindersNumber(int cyll_num);
            void set_Power(int power);
            // Getters
            std::string get_TradeMark() const;
            int get_CyllindersNumber() const;
            int get_Power() const;
            //Operators overloading
            friend std::ostream& operator<<(std::ostream& os, const Car& c);  // Stream output overloading
            Car& operator=(const Car& other); // assignment operator ovreload

              

    };

    // Define static member 'instance_number'
    int Car::instance_counter;

    // Define setter methods

    void Car::set_TradeMark(std::string trade_mark)
    {
        this->trading_mark_ = trade_mark;
    };

    void Car::set_CyllindersNumber(int cyll_num)
    {
        this->cyllinders_number_ = cyll_num;
    };

    void Car::set_Power(int power)
    {
        this->power_ = power;
    };

    // Define getter methods

     std::string Car::get_TradeMark() const
     {
        return this->trading_mark_;
     };

     int Car::get_CyllindersNumber() const
     {
        return this->cyllinders_number_;
     };

     int Car::get_Power() const
     {
        return this->power_;
     };

    // Define frendly function for getting of instance counter
    void getInstanceCount(const Car &c)
    {
        std::cout<< "Total number of vehicle objects: " <<c.instance_counter <<std::endl;

    };

    //Stream output operator overloading
    std::ostream& operator<<(std::ostream& os, const Car& c)
    {   
        os <<"Object ID: " << c.object_ID_<< std::endl << "Traiding mark: " << c.trading_mark_<< std::endl <<"Cyllinders: "
        << c.cyllinders_number_ << std::endl << "Power: " << c.power_ << std::endl;
        return os;
    };
    // Assignment operator overloading
    Car& Car::operator=(const Car& other)
    {
        this->trading_mark_ = other.trading_mark_;
        this->cyllinders_number_ = other.cyllinders_number_;
        this->power_ = other.power_;

        std::cout << "Assignment operator is working!" << std::endl;
        return *this;

    };

    //**************************************************** LORRY CLASS **************************************************************/

    class Lorry : public Car //Inheritance from Car class
    {
        private:
            
            int load_capacity_{0}; // Additional field in comparison to Car class
            
        public:
            //Default constructor
            Lorry()//:Car()  
            {
                
            }
            Lorry(std::string mark, int cyll, int power,int capacity)//:Car() 
            {                            
              this->trading_mark_ = mark;
              this->cyllinders_number_ = cyll;
              this->power_ = power;
              this->load_capacity_ = capacity;
              std::cout<<"Constructor with parameters is working!"<<std::endl;
            }
            // Copy constructor
            Lorry(const Lorry &L)//:Car()
            {
              this->trading_mark_ = L.trading_mark_;
              this->cyllinders_number_ = L.cyllinders_number_;
              this->power_ = L.power_;
              this->load_capacity_ = L.load_capacity_;
              std::cout<<"Copy constructor is working!"<<std::endl;
            }   
            ~Lorry()//Destructor
            {
                
            }
            // Getters
            int get_LoadCapacity() const;
            //Setters
            void set_LoadCapacity(int capacity) ;
            //Operators overloading
            friend std::ostream& operator<<(std::ostream& os, const Lorry& c); // Stream output overloading
            Lorry& operator=(const Lorry& other); // assignment operator ovreload

            
                
    };

    // Define getter methods

    int Lorry::get_LoadCapacity() const
    {
        return this->load_capacity_;
    };
    
    // Define setter methods

     void Lorry::set_LoadCapacity(int capacity) 
     {
        this->load_capacity_ = capacity;
     };

    //Stream output operator overloading
    std::ostream& operator<<(std::ostream& os, const Lorry& c)
    {   
        os <<"Object ID: " << c.object_ID_<< std::endl << "Traiding mark: " << c.trading_mark_<< std::endl <<"Cyllinders: " << c.cyllinders_number_ << std::endl 
        << "Power: " << c.power_ << std::endl<< "Load capacity: " << c.load_capacity_ << std::endl;
        return os;
    };

    // Assignment operator overloading
    Lorry& Lorry::operator=(const Lorry& other)
    {
        this->trading_mark_ = other.trading_mark_;
        this->cyllinders_number_ = other.cyllinders_number_;
        this->power_ = other.power_;

        std::cout << "Assignment operator is working!" << std::endl;
        return *this;

    };


};


int main()
{
    std::cout<<std::endl<<"************************* BEGIN ******************************"<<std::endl<<std::endl;

    std::cout<<std::endl<<"*********** CHECK CONSTRUCTORS WITH PARAMETERS ***************"<<std::endl<<std::endl;

    cars::Car C1("Car trade LTD",2,3);
    cars::Lorry L1("Lorry trade LTD",2,3,4);

    std::cout<<std::endl<<"**************** CHECK COPY CONSTRUCTORS *********************"<<std::endl<<std::endl;

    cars::Car C2 = C1;
    cars::Lorry L2 = L1;

    std::cout<<std::endl<<"*************** CHECK ASSIGNMENT OPERATORS *******************"<<std::endl<<std::endl;

    C2 = C1;
    C1 = C1;
    L2 = L1;
    L2 = L2;

    std::cout<<std::endl<<"************* CHECK STREAM OUTPUT OPERATORS *******************"<<std::endl<<std::endl;

    std::cout<<C1<<std::endl;
    std::cout<<L1<<std::endl;

    std::cout<<std::endl<<"************* CHECK GETTERS/SETTERS METHODS *******************"<<std::endl<<std::endl;
    
    C1.set_TradeMark("BMW");
    L1.set_TradeMark("KAMAZ");

    std::cout<<C1<<std::endl;
    std::cout<<L1<<std::endl;

    std::cout<<C1.get_TradeMark()<<std::endl;
    std::cout<<L1.get_TradeMark()<<std::endl;

    std::cout<<std::endl<<"***************** CHECK FRENDLY FUNCTION **********************"<<std::endl<<std::endl;
    
    std::cout << "Current number of objects: "<<std::endl;
    cars::getInstanceCount(C1);

    std::cout<<std::endl<<"********************* END OF ALL HOPES *************************"<<std::endl<<std::endl;
    

    return 0;
}





