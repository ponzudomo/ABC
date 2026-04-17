二段階で間違えた

# 1. アルゴリズムの採択ミス
URL: https://atcoder.jp/contests/abc453/submissions/74952059
貪欲で解けると思っていたが解けなかった

# 2. 正負のケアレスミス
URL: https://atcoder.jp/contests/abc453/submissions/75015072
原点を-0.5として解いていたのに、頭の中で0.5になっていた
変な調整をするのはやめた方がいいのかもしれない　この場合は全ての数字を2倍することで小数の概念を無くすのが良かった

# 3. cerr消し忘れでTLE
URL: https://atcoder.jp/contests/abc453/submissions/75015335
cerrって遅いらしい　提出するときに消したほうがいいっぽい

# 4. オーバーフロー
URL: https://atcoder.jp/contests/abc453/submissions/75015427
long long の最大値を一瞬`10^63-1`だと思ってスルーしてしまった　どう考えても`2^63-1`です😭
もっと普段から意識的に桁あふれを警戒した方がいい