var
  a:array[1..100] of longint;
  f1,f2:array[1..100] of longint;
  n,i,j,ans1,ans2:longint;
function max(a,b:longint):Longint;
begin
  max:=a;
  if max<b then max:=b;
end;
begin
  n:=0;
  fillchar(f1,sizeof(f1),0);
  fillchar(f2,sizeof(f2),0);
  while not eoln do
    begin
      inc(n);
      read(a[n]);
    end;
  for i:=1 to n do begin f1[i]:=1;f2[i]:=1;end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      begin
        if a[i]>=a[j] then f1[j]:=max(f1[j],f1[i]+1);
        if a[i]<a[j] then f2[j]:=max(f2[j],f2[i]+1);
      end;
  ans1:=f1[1];for i:=2 to n do ans1:=max(ans1,f1[i]);
  ans2:=f1[1];for i:=2 to n do ans2:=max(ans2,f2[i]);
  writeln(ans1,' ',ans2);
  readln;readln;
end.