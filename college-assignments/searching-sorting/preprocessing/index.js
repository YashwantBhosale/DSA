const fs = require('fs');
const path = require('path');

const files = fs.readdirSync(__dirname).filter(file => file.endsWith('.txt'));

files.forEach(file => {
    const data = fs.readFileSync(path.join(__dirname, file), 'utf8');
    let lines = data.split('\n');
    lines = lines.map(line => line.split('.')[0])
    lines = lines.join(',');


    fs.writeFileSync(path.join(__dirname, `${file.split('.')[0]}.csv`), lines);
});