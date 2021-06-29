const path = require('path');
const CopyPlugin = require("copy-webpack-plugin");

module.exports = {
  entry: './src/index.js',
  output: {
    filename: 'main.js',
    path: path.resolve(__dirname, 'dist')
  },
  mode: "development",
  plugins: [
    new CopyPlugin({
      patterns: [
        { from: "../../../resources" },
        { from: "../../../build/source/JsMaterialX/JsMaterialXGenShader.wasm" },
        { from: "../../../build/source/JsMaterialX/JsMaterialXGenShader.js" },
        { from: "../../../build/source/JsMaterialX/JsMaterialXGenShader.data" },
      ],
    }),
  ],
  externals: {
    JsMaterialX: 'JsMaterialX',
  },
};