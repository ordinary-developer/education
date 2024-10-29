import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true
    width: 640
    height: 480

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.assert(true, 'assertion for true')
            console.assert(false, 'assertion for false')

            console.count()

            console.debug('console.debug call')
            console.log('console.log call')
            console.info('console.info call')
            console.error('console.error call')
            console.warn('console.warn call')
            print('print call')

            console.profile()
            console.log('between console.profile() and console.profileEnd()')
            console.profileEnd()

            console.time('arbitrary_string')
            console.log('between console.time() and console.timeEnd()')
            console.timeEnd('arbitrary_string')

            console.trace()
        }
    }
}
