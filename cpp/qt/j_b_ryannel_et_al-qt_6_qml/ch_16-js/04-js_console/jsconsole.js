.pragma library

const scope = {
    // our custom scope injected into our function evaluation
}

function call(msg) {
    const exp = msg.toString()
    console.log(exp)
    const data = {
        expression : msg,
        result: "",
        error: ""
    }
    try {
        const fun = new Function('return (' + exp + ')')
        data.result = JSON.stringify(fun.call(scope), null, 2)
        console.log('scope: ' + JSON.stringify(scope, null, 2), 'result: ' + data.result)
    } catch(e) {
        console.log(e.toString())
        data.error = e.toString()
    }
    return data
}
