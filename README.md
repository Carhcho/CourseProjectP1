# CourseProjectP1
Programming 1 Course project
-----------------------------------------------------------------------------------------
Author: Cesar Roncancio
Date:   08/21/2021

Description:
This program will allow the user to keep track of airline reservations. The program should display the seating chart for the airplane. It will use an * to indicate a seat is taken and the # to indicate the seat is available. The program will also display a menu that provides the user with several options. There will be two types of seats in the airplane: first class and coach, each of which will have a different cost. The program must make use of files, arrays, and functions.
The airplane will have 5 rows in the first class section with 4 seats in each row, 2 on each side of the aisle, and 10 rows in the coach section with 3 seats on each side of the aisle. The prices for all the first-class seats will be the same. The first 5 rows of coach will be more expensive than the last 5 rows. The prices for the seats will be stored in a file called SeatPrices.txt. The program should read these values from the file and store the values in an array of doubles. This is an example of the seating chart:
<br>
     12 34 <br>
Row 1## ## <br>
Row 2## ## <br>
Row 3## ## <br>
Row 4## ## <br>
Row 5## ## <br>
<br>
    123456 <br>
Row 6###### <br>
Row 7###### <br>
Etc. <br>
<br>
The menu will provide choices to reserve a seat(s) and display the total number of seats sold (indicating first class and coach), the total number of seats empty in a row, the total number of seats empty in the plane (indicating first class and coach), and the total amount of sales (in dollars).
Validation: The seat requested by the user is a valid row and seat number. The program should also make sure the seat is not already taken.

Pseudocode: <br>
Start <br>
    -Declare variables and Functions <br>
    -Call function initialiseSeats <br>
    -Display "Enter 1 to reserve seat." <br>
    -Display "Enter 2 to display total number of seats sold." <br>
    -Display "Enter 3 to display total number of empty seats in the plane." <br>
    -Display "Enter 4 to display the sales." <br>
    -Display "Enter 5 to break." <br>
    -Display "\nPlease enter the choice: " <br>
    -Input choice <br>
    -IF choice is 1 call function reserveSeats <br>
    -If choice is 2 call function displaySoldSeats <br>
    -If choice is 3 call function displayEmpty <br>
    -If choice is 4 call function totalSales passing table[3] and int 3 <br>
    -If choice is 5 exit the program <br>
    -Function initialiseSeats <br>
    -For for rows and For for columns to fill the array with #s for firstClass[5][4] <br>
    -For for rows and For for columns to fill the array with #s for coachClass[10][6] <br>
    -Function seatMap <br>
    -For for rows and For for columns to show the arrays for firstClass[5][4] from column 0 to 1 then a space to simbolize the isle and For to show the rest of the column <br>
    -For for rows and For for columns to show the arrays for coachClass[10][6] <br>
    -Function reserveSeats <br>
    -Display "Section type: \nfirst \ncoach \nPlease enter type: " <br>
    -Input type <br>
    -If type entered is "first" <br>
    -Display "Enter row number: " <br>
    -Input row <br>
    -Display "Enter seat number: " <br>
    -Input seat <br>
    -If row entered is less than 1 or higher than 5 or seat entered is less than 1 or higher than 4 <br>
    -Display "Invalid seat location." <br>
    -If the row and seat entered aleary has a * on the 2D array <br>
    -Display "This seat is already taken, try another" <br>
    -If type entered is "coach" <br>
    -Display "Enter row number: " <br>
    -Input row <br>
    -Display "Enter seat number: " <br>
    -Input seat <br>
    -If row entered is less than 1 or higher than 10 or seat entered is less than 1 or higher than 6 <br>
    -Display "Invalid seat location." <br>
    -If the row and seat entered aleary has a * on the 2D array <br>
    -Display "This seat is already taken, try another" <br>
    -Else to the first If Display "Section type doesn't exist, try again." <br>
    -Function displaySoldSeats <br>
    -For for rows and For for columns to fill the array with #s for firstClass[5][4] adding 1 to the total for every * <br>
    -For for rows and For for columns to fill the array with #s for coachClass[10][6] adding 1 to the total for every * <br>
    -Display "Total number of seats sold: " <br>
    -Display total <br>
    -Call seatMap <br>
    -Function displayEmpty <br>
    -For for rows and For for columns to fill the array with #s for firstClass[5][4] adding 1 to the totalSeats for every # <br>
    -For for rows and For for columns to fill the array with #s for coachClass[10][6] adding 1 to the totalSeats for every # <br>
    -Display "Total number of empty seats in the plane: " <br>
    -Display totalSeats <br>
    -Function totalSales receives double array and a integer <br>
    -Open "SeatPrices.txt" <br>
    -If the file is not found <br>
    -Display "File failed to load, please try again." <br>
    -For every position on table[] assign a value from each line of SeatPrices.txt <br>
    -Close file <br>
    -price1 gets assign the value on table[0] <br>
    -price2 gets assign the value on table[1] <br>
    -price3 gets assign the value on table[2] <br>
    -total = 0 <br>
    -For every * (sold seat) add total to price1 and make that sum the new total in the firstClass[ ][ ] <br>
    -For every * (sold seat) in the first 5 positions add total to price1 and make that sum the new total in the coachClass[ ][ ] <br>
    -For every * (sold seat) in the next 5 positions add total to price1 and make that sum the new total in the coachClass[ ][ ] <br>
    -Display "Total sales: " <br>
    -Display total <br>
End
