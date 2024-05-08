import json


def main():
    team_details = []
    with open("team_details.txt", "r") as file:
        for line in file:
            team_details.append(line.split())

    with open("students_info.json", "r") as file:
        students_info = json.load(file)

    for student in students_info:
        for entry in team_details:
            if entry[2] == student["id"]:
                student["name"] = f"{entry[0]} {entry[1]}"
                student["section"] = entry[3]
                student["level"] = "2"
                student["email"] = entry[4]

    with open("students_info_full.json", "w") as file:
        json.dump(students_info, file, indent=4)


if __name__ == "__main__":
    main()
