import json
import pandas


def main():
    df = pandas.read_excel(
        "students_info.xlsx", names=["id", "phone", "program"], header=None
    )
    entries = []

    for index, row in df.iterrows():
        entry = {
            "name": "",
            "program": row["program"],
            "level": "",
            "email": "",
            "phone": row["phone"],
            "id": row["id"],
            "section": "",
        }
        entries.append(entry)

    with open("students_info.json", "w") as f:
        json.dump(entries, f, indent=4)


if __name__ == "__main__":
    main()
