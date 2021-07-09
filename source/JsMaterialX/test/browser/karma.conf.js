module.exports = function(config) {
    config.set({
        basePath: '../', // base is the test folder
        frameworks: ['mocha', 'chai'],
        files: [
          { pattern: '_build/JsMaterialXGenShader.js', watched: false, included: false, served: true, type: 'module'},
          { pattern: '_build/JsMaterialXGenShader.wasm', watched: false, included: false, served: true, type: 'wasm'},
          { pattern: '_build/JsMaterialXGenShader.data', watched: false, included: false, served: true, type: 'data'},
          { pattern: 'browser/*.spec.js', watched: true, included: true, served: true, type: 'module'},
        ],
        mime: {
         'application/wasm': ['wasm'],
         /*'application/octet-stream*/'; charset=UTF-8': ['data']
        },
        proxies: {
          '/_build/JsMaterialXGenShader.js': '/base/_build/JsMaterialXGenShader.js',
          '/JsMaterialXGenShader.wasm': '/base/_build/JsMaterialXGenShader.wasm',
          '/JsMaterialXGenShader.data': '/base/_build/JsMaterialXGenShader.data',
        },
        proxyReq: function(proxyReq, req, res, options) {
          proxyReq.setHeader('Range', 'bytes=0-');
          // proxyReq.setHeader('Transfer-Encoding', 'identity');
        },
        proxyRes: function(proxyRes, req, res) {
          // delete proxyRes.headers['content-range'];
          // delete proxyRes.headers['cache-control'];
          // delete proxyRes.headers['pragma'];
          // delete proxyRes.headers['expires'];
        },
        reporters: ['progress'],
        port: 8080,
        colors: true,
        logLevel: config.LOG_DEBUG,
        browsers: ['ChromeHeadlessNoSandbox'],
        customLaunchers: {
            ChromeHeadlessNoSandbox: {
                base: 'ChromeHeadless',
                flags: ['--no-sandbox', '--headless']
            }
        },
        autoWatch: true,
        concurrency: Infinity,
        plugins: [
            'karma-mocha',
            'karma-chai',
            'karma-chrome-launcher'
        ],
    })
}