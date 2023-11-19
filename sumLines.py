# sumLines.py

import sys

def sum_lines(file_path):
    try:
        # Open the file in read mode
        with open(file_path, 'r') as file:
            sum_total = 0
            num_elements = 0

            # Iterate through each line in the file
            for line in file:
                # Split the line into a list of integers
                numbers = list(map(int, line.split()))

                # Update sum and number of elements
                sum_total += sum(numbers)
                num_elements += len(numbers)

            # Calculate the average
            average = sum_total / num_elements if num_elements > 0 else 0

            # Print the results
            print(f"Where sum = {sum_total}, Number of Elements = {num_elements}, and Average = {average}")

    except FileNotFoundError:
        print(f"Error: File '{file_path}' not found.")
    except Exception as e:
        print(f"An error occurred: {e}")

if __name__ == "__main__":
    # Check if the correct number of command-line arguments is provided
    if len(sys.argv) != 2:
        print("Usage: python3 sumLines.py <input_file>")
        sys.exit(1)

    # Get the file path from the command-line argument
    input_file = sys.argv[1]

    # Call the sum_lines function with the provided file path
    sum_lines(input_file)

