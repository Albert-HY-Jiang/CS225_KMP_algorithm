def filter_dna_sequence_in_file(input_file_path, max_size_mb=1):
    """
    Reads a text file, filters its content to include only the letters A, T, C, G,
    and writes the result to a new file until the output file reaches a specified size limit.
    """
    max_size_bytes = max_size_mb * 1024 * 1024  # Convert MB to bytes
    output_file_path = input_file_path.rsplit('.', 1)[0] + '_filtered.txt'

    try:
        with open(input_file_path, 'r') as input_file, open(output_file_path, 'w') as output_file:
            allowed_chars = set('ATCG')

            while True:
                chunk = input_file.read(1024)  # Read in chunks to handle large files
                if not chunk:
                    break  # End of file

                filtered_chunk = ''.join(char for char in chunk if char in allowed_chars)
                output_file.write(filtered_chunk)

                if output_file.tell() >= max_size_bytes:
                    break  # Stop writing if file size exceeds limit

        return output_file_path
    except Exception as e:
        return str(e)


def filter_dna_sequence_in_file(file_path):
    """
    Reads a text file, filters its content to include only the letters A, T, C, G,
    and writes the result back to a new file.
    """
    try:
        with open(file_path, 'r') as file:
            text = file.read()
            allowed_chars = set('ATCG')
            filtered_text = ''.join(char for char in text if char in allowed_chars)

        output_file_path = file_path.rsplit('.', 1)[0] + '_filtered.txt'
        with open(output_file_path, 'w') as output_file:
            output_file.write(filtered_text)

        return output_file_path
    except Exception as e:
        return str(e)

def create_multiple_output_files(input_file_path, num_files=100):
    """
    Creates multiple output files with increasing sizes, each having 10 times the number
    of characters as the previous one, taking content from different parts of the input file.
    """
    output_files = []

    try:
        with open(input_file_path, 'r') as input_file:
            input_text = input_file.read()

        # Calculate the length of each file
        initial_length = 100
        print(len(input_text))

        for i in range(num_files):
            output_file_name = f'output_file_{i + 1}.txt'
            output_files.append(output_file_name)

            start_index = i * initial_length
            end_index = start_index + initial_length * (10 * i)

            with open(output_file_name, 'w') as output_file:
                # Add a blank line before writing the content
                output_file.write("\n")
                output_file.write(input_text[start_index:end_index])

        return output_files
    except Exception as e:
        return str(e)


input_file_path = 'SRR000056_filtered.txt'

output_files = create_multiple_output_files(input_file_path)
