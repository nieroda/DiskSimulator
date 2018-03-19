

const getRandomTrack  = () => Math.floor(Math.random() * 99)
const getRandomSector = () => Math.floor(Math.random() * 29)

(() => {
    for (let i = 20; i < 70000; i += Math.floor(Math.random() * 20)) 
        console.log(`${i} ${getRandomTrack()} ${getRandomSector()}`)
})()

