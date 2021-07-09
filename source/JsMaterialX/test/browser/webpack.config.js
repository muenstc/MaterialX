const path = require('path');
const CopyPlugin = require("copy-webpack-plugin");
const HtmlWebpackPlugin = require('html-webpack-plugin');

module.exports = {
  entry: './browser/index.js',
  output: {
    filename: 'browser.test.js',
    path: path.resolve(__dirname, 'dist'),
    publicPath: '/browser'
  },
  devServer: {
    open: true,
    openPage: 'browser'
  },
  resolve: {
    fallback: {
      fs: false,
      path: false,
      crypto: false,
    }
  },
  mode: "development",
  plugins: [
    new CopyPlugin({
      patterns: [
        { from: "_build/JsMaterialXGenShader.wasm" },
        { from: "_build/JsMaterialXGenShader.data" },
      ],
    }),
    new HtmlWebpackPlugin(),
  ]
};
