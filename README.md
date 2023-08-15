# CourseProjectP1
Programming 1 Course project
/*****************************************************************************
Author: Cesar Roncancio
Date:   08/21/2021

Description:
This program will allow the user to keep track of airline reservations. The program should display the seating chart for the airplane. It will use an * to indicate a seat is taken and the # to indicate the seat is available. The program will also display a menu which provides the user with several options. There will be two types of seats in the airplane: first class and coach, each of which will have a different cost. The program must make use of files, arrays and functions.
The airplane will have 5 rows in the first class section with 4 seats in each row, 2 on each side of the aisle and 10 rows in the coach section with 3 seats on each side of the aisle. The prices for all the first class seats will be the same. The first 5 rows of coach will be more expensive than the last 5 rows. The prices for the seats will be stored in a file called SeatPrices.txt . The program should read these values from the file and store the values in an array of doubles. This is an example of the seating chart:

     12 34
Row 1## ##
Row 2## ##
Row 3## ##
Row 4## ##
Row 5## ##

     123456
Row 6######
Row 7######
Etc.

The menu will provide choices to reserve a seat(s) and display the total number of seats sold (indicating first class and coach), the total number of seats empty in a row, the total number of seats empty in the plane (indicating first class and coach), and the total amount of sales (in dollars).
Validation: The seat requested by the user is a valid row and seat number. The program should also make sure the seat is not already taken.

Pseudocode:
Start
    -Declare variables and Functions
    -Call function initialiseSeats
    -Display "Enter 1 to reserve seat."
    -Display "Enter 2 to display total number of seats sold."
    -Display "Enter 3 to display total number of empty seats in the plane."
    -Display "Enter 4 to display the sales."
    -Display "Enter 5 to break."
    -Display "\nPlease enter the choice: "
    -Input choice
    -IF choice is 1 call function reserveSeats
    -If choice is 2 call function displaySoldSeats
    -If choice is 3 call function displayEmpty
    -If choice is 4 call function totalSales passing table[3] and int 3
    -If choice is 5 exit the program
    -Function initialiseSeats
    -For for rows and For for columns to fill the array with #s for firstClass[5][4]
    -For for rows and For for columns to fill the array with #s for coachClass[10][6]
    -Function seatMap
    -For for rows and For for columns to show the arrays for firstClass[5][4] from column 0 to 1 then a space to simbolize the isle and For to show the rest of the column
    -For for rows and For for columns to show the arrays for coachClass[10][6]
    -Function reserveSeats
    -Display "Section type: \nfirst \ncoach \nPlease enter type: "
    -Input type
    -If type entered is "first"
    -Display "Enter row number: "
    -Input row
    -Display "Enter seat number: "
    -Input seat
    -If row entered is less than 1 or higher than 5 or seat entered is less than 1 or higher than 4
    -Display "Invalid seat location."
    -If the row and seat entered aleary has a * on the 2D array
    -Display "This seat is already taken, try another"
    -If type entered is "coach"
    -Display "Enter row number: "
    -Input row
    -Display "Enter seat number: "
    -Input seat
    -If row entered is less than 1 or higher than 10 or seat entered is less than 1 or higher than 6
    -Display "Invalid seat location."
    -If the row and seat entered aleary has a * on the 2D array
    -Display "This seat is already taken, try another"
    -Else to the first If Display "Section type doesn't exist, try again."
    -Function displaySoldSeats
    -For for rows and For for columns to fill the array with #s for firstClass[5][4] adding 1 to the total for every *
    -For for rows and For for columns to fill the array with #s for coachClass[10][6] adding 1 to the total for every *
    -Display "Total number of seats sold: "
    -Display total
    -Call seatMap
    -Function displayEmpty
    -For for rows and For for columns to fill the array with #s for firstClass[5][4] adding 1 to the totalSeats for every #
    -For for rows and For for columns to fill the array with #s for coachClass[10][6] adding 1 to the totalSeats for every #
    -Display "Total number of empty seats in the plane: "
    -Display totalSeats
    -Function totalSales receives double array and a integer
    -Open "SeatPrices.txt"
    -If the file is not found
    -Display "File failed to load, please try again."
    -For every position on table[] assign a value from each line of SeatPrices.txt
    -Close file
    -price1 gets assign the value on table[0]
    -price2 gets assign the value on table[1]
    -price3 gets assign the value on table[2]
    -total = 0
    -For every * (sold seat) add total to price1 and make that sum the new total in the firstClass[][]
    -For every * (sold seat) in the first 5 positions add total to price1 and make that sum the new total in the coachClass[][]
    -For every * (sold seat) in the next 5 positions add total to price1 and make that sum the new total in the coachClass[][]
    -Display "Total sales: "
    -Display total
End
*******************************************************************************/
