module.exports = function string(length) {
    let string = '';
    let allowed = 'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789';
    for ( let i = 0; i < length; i++ ) {
      string += allowed.charAt(Math.floor(Math.random() * allowed.length));
    };
    return string;
};