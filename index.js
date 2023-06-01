const fs = require("fs");
const simpleGit = require("simple-git");
const jsonfile = require("jsonfile");
const moment = require("moment");

const FILE_PATH = "./data.json";

const getDates = async (startDateStr) => {
  let currentDate = new Date(startDateStr);
  const endDate = new Date("2022-08-20T00:00:00+03:00");

  while (currentDate <= endDate) {
    let formattedDate =
      currentDate.toUTCString().slice(0, -4) + "+03:00";
    const data = {
      date: formattedDate,
    };
    if (Math.random() < 0.6) {
      jsonfile.writeFileSync(FILE_PATH, data);
      console.log(fs.readFileSync("data.json", "utf8"));
      await simpleGit()
        .add([FILE_PATH])
        .commit(formattedDate, { "--date": formattedDate })
        .push();
    }
    currentDate.setDate(currentDate.getDate() + 1);
  }
};

getDates("2021-02-22T00:41:28+03:00");


