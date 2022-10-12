const axios = require('axios');

const checkIn = async (cookie) => {
    return axios({
        method: 'post',
        url: 'https://glados.rocks/api/user/checkin',
        headers: {
            'cookie': cookie
        },
        data: {
            token: "glados_network"
        }
    });
};

const getStatus = async (cookie) => {
    return axios({
        method: 'get',
        url: 'https://glados.rocks/api/user/status',
        headers: {
            'Cookie': cookie
        }
    });
};

const checkInAndGetStatus = async (cookie) => {
    const checkInMessage = (await checkIn(cookie))?.data?.message;

    const userStatus = (await getStatus(cookie))?.data?.data;
    const email = userStatus?.email;
    const leftDays = parseInt(userStatus?.leftDays);

    return {
        '账号': email,
        '天数': leftDays,
        '签到情况': checkInMessage
    };
};

const pushplus = (token, infos) => {
    const titleEmail = infos?.[0]['账号'];
    const titleLeftDays = infos?.[0]['天数'];
    const titleCheckInMessage = infos?.[0]['签到情况'];
    const titleSpace = 4;

    const title = (
        '账号: ' + `${titleEmail}`.padEnd(titleEmail.length + titleSpace) +
        '天数: ' + `${titleLeftDays}`.padEnd(titleLeftDays.toString().length + titleSpace) +
        '签到情况: ' + `${titleCheckInMessage}`
    ).slice(0, 100);  //pushplus标题最大长度为100

    const data = {
        token,
        title,
        content: JSON.stringify(infos),
        template: 'json'
    };
    console.log(data);

    return axios({
        method: 'post',
        url: `http://www.pushplus.plus/send`,
        data
    });
};

const GLaDOSCheckIn = async () => {
    try {

        const cookies = '_ga=GA1.2.1351194876.1664900941; _gid=GA1.2.909984829.1664900941; koa:sess=eyJ1c2VySWQiOjEwNjk3NiwiX2V4cGlyZSI6MTY5MDgyMDk2NzI3MCwiX21heEFnZSI6MjU5MjAwMDAwMDB9; koa:sess.sig=7qWgkCjSa60tsoMSMRvoeM-PSOY; __stripe_mid=966a2d8d-4c59-4173-a333-eee6870b32094d8e2d';

        const infos = await Promise.all(cookies.map(async cookie => await checkInAndGetStatus(cookie)));  //虽然map方法的参数是async函数，但它是并发执行的，因为只有async函数内部是继发执行，外部不受影响。
        console.log(infos);

        const PUSHPLUS = '066188e838394224b79f2fff52597f03';

        if (PUSHPLUS && infos.length) {
            const pushResult = (await pushplus(PUSHPLUS, infos))?.data?.msg;
            console.log(pushResult);
        }
    } catch (error) {
        console.log(error);
    }
};

GLaDOSCheckIn();



