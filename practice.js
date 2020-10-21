document.querySelector(".volumeIcon").click(); //静音处理
document.getElementsByClassName("speedTab15")[0].click(); //1.5倍速播放
setInterval(function () {
  //每3秒执行一次
  //判断播放进度是否到达100%
  if (document.getElementsByClassName("passTime")[0].style.width == "100%") {
    setTimeout(function () {
      //用js执行“下一集”按钮的点击事件，延迟1s执行
      document.getElementById("nextBtn").click();
    }, 1000);
    setTimeout(function () {
      //延迟4秒执行调节播放速率
      document.querySelector(".volumeIcon").click();
      document.getElementsByClassName("speedTab15")[0].click(); //先设置一下播放速率为1.5倍速
    }, 4000);
  }

  if (
    document.getElementsByClassName("bigPlayButton pointer")[0].style.display ==
    "block"
  ) {
    //用于检测答题弹窗是否出现，并将其关闭
    document.getElementsByClassName("topic-item")[0].click(); //只选A，弹窗题目不影响成绩，就不纠结选的对不对了
    document.getElementsByClassName("el-dialog__footer")[5].click();
    document.getElementsByClassName("el-dialog__headerbtn")[5].click(); //点击按钮关闭
    document.getElementsByClassName("playButton")[0].click(); //点击播放继续
  }
}, 3000);
