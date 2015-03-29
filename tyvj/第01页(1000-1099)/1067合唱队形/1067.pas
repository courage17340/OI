var
  opt1,opt2,a:array[0..200] of longint;
  n,ans,i,j:longint;
begin
  fillchar(opt1,sizeof(opt1),0);
  fillchar(opt2,sizeof(opt2),0);
  read(n);
  for i:=1 to n do read(a[i]);
  a[0]:=-maxlongint;
  for i:=1 to n do
    for j:=i-1 downto 0 do
      if (a[j]<a[i])and(opt1[j]+1>opt1[i])
        then opt1[i]:=opt1[j]+1;
  a[n+1]:=-maxlongint;
  for i:=n downto 1 do
    for j:=i+1 to n+1 do
      if (a[j]<a[i])and(opt2[j]+1>opt2[i])
        then opt2[i]:=opt2[j]+1;
  ans:=0;
  for i:=1 to n do
    if opt1[i]+opt2[i]>ans then ans:=opt1[i]+opt2[i];
  writeln(n-ans+1);
end.