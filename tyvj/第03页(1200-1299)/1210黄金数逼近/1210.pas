var
  a:array[-1..10000] of qword;
  i:longint;
  n:qword;
begin
  readln(n);
  a[-1]:=1;
  a[0]:=1;
  a[1]:=1;
  for i:=2 to 10000 do a[i]:=a[i-1]+a[i-2];
  i:=0;
  while a[i+1]<n do inc(i);
  writeln(a[i-1],'/',a[i]);
  readln;
end.