/* ========================================================================== */
/*  PROGRAM Stock Price Simulator
    AUTHOR: <Kelli Kinnikin and Alex Grant>
    COURSE NUMBER: <CIS 210>
    COURSE SECTION NUMBER: <01>
    INSTRUCTOR NAME: <Guanyu Tian>
    PROJECT NUMBER: <6>
    DUE DATE: 10/05/2017  

SUMMARY:
The main program will ask user to enter a name, symbol, current price of a stock. Then, it
simulates the prices for next 30 days. It displays the prices for the next 30 days on the
console and to a file named output.csv. The Stock class should have a SimulatePrice() method,
which increases or decreases the currentPrice by 0 - 10% randomly, such as 0.56% and 9.65%.

INPUT:
>stock's name
>symbol
>current price

OUTPUT:
>stock's name
>symbol
>currentPrice
>nextPrice
>priceChange
>priceChangePercentage 
*/
import java.util.Scanner;

public class StockPriceSimulator {
	public static void main(String[] args){
		//Variables
		String companyName = new String();//companyName variable: new String Method
		String companySymbol = new String();//companySymbol variable: new String Method
		double currentPrice = 0;//currentPrice set to 0: before user input
		double nextPrice = 0;//nextPrice set to 0: before user input
		double percentChange = 0;//percentChange set to 0: before user input
		final int NUMBER_OF_DAYS = 30;//NUMBER_OF_DAYS set to 30: 
				
		Scanner compNameInput = new Scanner(System.in);	//This creates an object for the company name input
		Scanner compSymbolInput = new Scanner(System.in);//This creates an object for the company symbol input
		Scanner currentPriceInput = new Scanner(System.in);//This creates an object for the current price input
		
		Stock object = new Stock();
		//This prints out the condition for using default values
		System.out.print("If the user enters NONE, NA, and 0.0 for the name of the company, the symbol, and yesterday's price ");
		System.out.println("respectively, it will use default values.");
		
		System.out.print("Please enter the name of the stock: ");
		
		companyName = compNameInput.nextLine();//User enters the company name
		System.out.print("Please enter the symbol of the stock: ");
		companySymbol = compSymbolInput.nextLine();//User enters the company symbol
		System.out.print("Please enter yesterday's price: ");
		currentPrice = currentPriceInput.nextDouble();//User enters the current price 
		
		//This determines if the default values should be used
		object.WhichDefaultValue(companyName, companySymbol, currentPrice);
		object.priceChange();
		companyName = object.getName();//This assigns the company name to the variable
		companySymbol = object.getSymbol();//This assigns the company symbol to the variable
		currentPrice = object.getCurrentPrice();//This assigns the current price to the variable
		nextPrice = object.getNextPrice();//This assigns the current price to the variable
		//This assigns the next price to the variable
		percentChange = object.getPercentage();
		object.printHeaders();//This prints the category headers for each column
		
		//This starts the for loop that iterates for 30 times
		for(int i=1; i<=NUMBER_OF_DAYS; i++) {
			//This prints out the stock description
			object.printResults(companyName, companySymbol, currentPrice, nextPrice, percentChange);
			object.setCurrentPrice(nextPrice);//This sets the current price to the value of the next price
			object.priceChange();//This changes the price of the next price
			currentPrice = object.getCurrentPrice();//This assigns the current price to the variable
			nextPrice = object.getNextPrice();//This assigns the next price to the variable
			percentChange = object.getPercentage();//This assigns the percentage to the variable
		}//Closes 'for' loop
                
		//This closes the input objects
		compNameInput.close();
		compSymbolInput.close();
		currentPriceInput.close();
		
	}//Closes Main Method
}//Closes PriceStockSimulation Class