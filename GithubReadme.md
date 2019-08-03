# [生成 GitHub README.md 目录](https://sleepeatcode.com/articles/15/generating-the-github-readme-directory)



1. 在创建 GitHub 项目时，想要给 README.md 文档加上目录，本以为直接使用 `[TOC]` 可以自动生成目录，跟其它的 Markdown 编辑器一样，但是发现 GitHub 并不支持。搜索了一下相关的问题，分享一下。

2. GitHub 使用的 Markdown 是 Github Flavored Markdown，简称 GFM，参考 GitHub 官方的 [GitHub Flavored Markdown Spec](https://github.github.com/gfm/)，Markdown 的目录使用页面内 Anchor 锚点跳转。

   ```
     * [标题1](#标题1)
     * [标题2](#标题2)
     * [标题3](#标题3)
           * [标题3.1](#标题3.1)
           * [标题3.2](#标题3.2)
     * [标题4](#标题4)
   ```

   