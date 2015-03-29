type
  arr=record num,score:longint;end;
var
  a:array[0..5000] of arr;
  i,j,m,n:longint;
procedure swap(var a,b:arr);
var t:arr;
begin
  t:=a;a:=b;b:=t;
end;
begin
  readln(n,m);
  for i:=1 to n do read(a[i].num,a[i].score);
  a[n+1].score:=-1;
  m:=trunc(m*1.5);
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if (a[i].score<a[j].score)or(a[i].score=a[j].score)and(a[i].num>a[j].num) then swap(a[i],a[j]);
  n:=m;
  m:=a[m].score;
  while a[n].score=m do inc(n);
  writeln(m,' ',n-1);
  for i:=1 to n-1 do writeln(a[i].num,' ',a[i].score);
end.