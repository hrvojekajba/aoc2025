def get_input():
    item_list = []

    file = open("input.txt")
    file_content = file.read().split(",")

    for item in file_content:
        item = item.strip()
        item_list.append(item)

    return item_list


def part_one(id_list):
    invalid_total = 0

    for pair in id_list:
        id1, id2 = pair.split("-")

        for number in range(int(id1), int(id2) + 1):
            string_number = str(number)
            number_length = len(string_number)

            if string_number[number_length // 2 :] == string_number[: number_length // 2]:
                invalid_total += number

    print(f"Total - PART 1: {invalid_total}")


def part_two(id_list):
    invalid_total = 0
    for pair in id_list:
        id1, id2 = pair.split("-")
        for number in range(int(id1), int(id2) + 1):
            number = str(number)
            for slice_size in range(1, len(number)):
                slice = number[0:slice_size]
                new_number = number.replace(slice, "")
                if new_number == "":
                    invalid_total += int(number)
                    break

    print(f"Total - PART 2: {invalid_total}")


if __name__ == "__main__":
    id_list = get_input()
    part_one(id_list)
    part_two(id_list)
