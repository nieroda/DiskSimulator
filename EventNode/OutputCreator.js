

let getRandomTrack = () => ( Math.floor( Math.random() * 99 ) );
let getRandomSector = () => ( Math.floor( Math.random() * 29 ) );

function getAll() {
    for (let i = 20; i < 70000; i += Math.floor(Math.random() * 20)) {
        console.log(`${i} ${getRandomTrack()} ${getRandomSector()}`);
    }
}



getAll();
