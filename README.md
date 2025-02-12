#exsample how to run hook lib using
method static constructor <clinit>()V

    .registers 1
    .line 1
    :try_start_0
    const-string v0, "Mylib"
    invoke-static {v0}, Ljava/lang/System;->loadLibrary(Ljava/lang/String;)V
