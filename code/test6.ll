; ModuleID = 'hello'
source_filename = "hello"

@0 = private unnamed_addr constant [2 x i8] c"\0A\00"
@ans = internal global i32 zeroinitializer, align 4
@1 = private unnamed_addr constant [4 x i8] c"%d \00"

define void @main() {
entry:
  %callproc = call i32 @gcd(i32 9, i32 36)
  %callproc1 = call i32 @gcd(i32 3, i32 6)
  %multmp = mul i32 %callproc, %callproc1
  store i32 %multmp, i32* @ans
  %0 = load i32, i32* @ans
  %1 = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @1, i32 0, i32 0), i32 %0)
  %2 = call i32 @puts(i8* getelementptr inbounds ([2 x i8], [2 x i8]* @0, i32 0, i32 0))
  ret void
}

declare i32 @puts(i8*)

declare i32 @scanf(i8*, ...)

declare i32 @printf(i8*, ...)

define i32 @gcd(i32 %a, i32 %b) {
entry:
  %gcd = alloca i32
  %a1 = alloca i32
  store i32 %a, i32* %a1
  %b2 = alloca i32
  store i32 %b, i32* %b2
  %0 = load i32, i32* %b2
  %cmptmp = icmp eq i32 %0, 0
  br i1 %cmptmp, label %then, label %else

then:                                             ; preds = %entry
  %1 = load i32, i32* %a1
  store i32 %1, i32* %gcd
  br label %ifcont

else:                                             ; preds = %entry
  %2 = load i32, i32* %b2
  %3 = load i32, i32* %a1
  %4 = load i32, i32* %b2
  %modtmp = urem i32 %3, %4
  %callproc = call i32 @gcd(i32 %2, i32 %modtmp)
  store i32 %callproc, i32* %gcd
  br label %ifcont

ifcont:                                           ; preds = %else, %then
  %5 = load i32, i32* %gcd
  ret i32 %5
}
