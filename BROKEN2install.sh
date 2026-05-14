#!/usr/bin/env bash

git clone https://github.com/iam2soup/RAGcloth.git
cd RAGcloth || exit 1
sudo -v || exit 1
sudo bash lin2build.sh
