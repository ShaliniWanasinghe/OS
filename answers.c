Q9


if [ $# -eq 0 ]; then
  echo "Usage: $0 number1 number2 ... numberN"
  exit 1
fi


for num in "$@"; do
  echo "$num"
done | sort -nr
------------------------output---------------------------------------

Q10

get_grade() {
  mark=$1
  if [ "$mark" -ge 90 ]; then
    echo "A"
  elif [ "$mark" -ge 80 ]; then
    echo "B"
  elif [ "$mark" -ge 70 ]; then
    echo "C"
  elif [ "$mark" -ge 60 ]; then
    echo "D"
  else
    echo "F"
  fi
}


read -p "Enter student's name: " name
read -p "Enter marks for Subject 1: " sub1
read -p "Enter marks for Subject 2: " sub2
read -p "Enter marks for Subject 3: " sub3

total=$((sub1 + sub2 + sub3))
average=$((total / 3))

grade1=$(get_grade "$sub1")
grade2=$(get_grade "$sub2")
grade3=$(get_grade "$sub3")

echo ""
echo "--- Student Marksheet ---"
echo "Name        : $name"
echo "Subject 1   : $sub1 (Grade: $grade1)"
echo "Subject 2   : $sub2 (Grade: $grade2)"
echo "Subject 3   : $sub3 (Grade: $grade3)"
echo "Total Marks : $total"
echo "Average     : $average"

Q11

read -p "Enter a number: " num

echo ""
echo "Multiplication Table for $num"
echo " -------------------------- "


for i in {1..10}
do
  result=$((num * i))
  echo "$num x $i = $result"
done

--------output

[2021ict75@fedora rev_exercise]$ vi Q1
[2021ict75@fedora rev_exercise]$ chmod 777 Q1
[2021ict75@fedora rev_exercise]$ ./Q1
Enter student's name: Shalini
Enter marks for Subject 1: 89
Enter marks for Subject 2: 98
Enter marks for Subject 3: 80

--- Student Marksheet ---
Name        : Shalini
Subject 1   : 89 (Grade: B)
Subject 2   : 98 (Grade: A)
Subject 3   : 80 (Grade: B)
Total Marks : 267
Average     : 89

---------------------------------------------------------------------

Q16


read -p "Enter a year: " year


if (( year % 400 == 0 )); then
  echo "$year is a Leap Year."
elif (( year % 100 == 0 )); then
  echo "$year is NOT a Leap Year."
elif (( year % 4 == 0 )); then
  echo "$year is a Leap Year."
else
  echo "$year is NOT a Leap Year."
fi
-----output
[2021ict75@fedora rev_exercise]$ vi q2.sh
[2021ict75@fedora rev_exercise]$ chmod 777 q2.sh
[2021ict75@fedora rev_exercise]$ ./q2.sh
Enter a number: 2

Multiplication Table for 2
 --------------------------
2 x 1 = 2
2 x 2 = 4
2 x 3 = 6
2 x 4 = 8
2 x 5 = 10
2 x 6 = 12
2 x 7 = 14
2 x 8 = 16
2 x 9 = 18
2 x 10 = 20

-------------------------------------------------------------------------------
Q17


today_day=$(date +%d)
today_month=$(date +%m)


read -p "Enter your birth day (DD): " birth_day
read -p "Enter your birth month (MM): " birth_month


if [[ "$birth_day" == "$today_day" && "$birth_month" == "$today_month" ]]; then
  echo " Happy Birthday!  Wishing you a fantastic day!"
else
  echo "Today is not your birthday, but I hope you're having a great day anyway!"
fi

----output

[2021ict75@fedora rev_exercise]$ vi Q4.sh
[2021ict75@fedora rev_exercise]$ chmod 777 Q4.sh
[2021ict75@fedora rev_exercise]$ ./Q4.sh
Enter your birth day (DD): 12
Enter your birth month (MM): 05
Today is not your birthday, but I hope you're having a great day anyway!
[2021ict75@fedora rev_exercise]$ ./Q4.sh
Enter your birth day (DD): 23
Enter your birth month (MM): 06
 Happy Birthday!  Wishing you a fantastic day!


