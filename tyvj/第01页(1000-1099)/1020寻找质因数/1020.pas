type
  arr=record
        v,z:longint;
      end;
var
  a:array[0..5000] of longint;
  f:array[0..20000] of 0..1;
  n,i:longint;
  ans:arr;
procedure work(i:longint);
var j,k,x,k1:longint;
begin
  x:=a[i];
  fillchar(f,sizeof(f),0);
  f[1]:=1;
  k1:=0;
  while x>1 do
    begin
      k:=2;
      while x mod k<>0 do inc(k);
      f[k]:=1;
      x:=x div k;
      if k1<k then k1:=k;
    end;
  if k1=0 then k1:=1;
  if ans.z<k1 then
    begin
      ans.v:=a[i];
      ans.z:=k1;
    end;
end;
begin
  read(n);
  for i:=1 to n do read(a[i]);
  ans.v:=0;ans.z:=0;
  for i:=1 to n do work(i);
  writeln(ans.v);
end.