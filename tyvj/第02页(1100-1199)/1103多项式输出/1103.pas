var
  i,n:longint;
  a:array[0..10000] of longint;
procedure print(x:longint);
begin
  if abs(a[x])<>1 then write(a[i]) else
    if (a[x]=-1)and(x<>n+1) then write('-');
  if (abs(a[x])=1)and(x=n+1) then write(a[x]);
  if n-x<>-1 then write('x');
  if (n-x<>-1)and(n-x<>0) then write('^',n-x+1);
end;
begin
  readln(n);
  a[n+1]:=-1;
  for i:=1 to n+1 do read(a[i]);
  i:=1;
  while a[i]=0 do inc(i);
  if i>n then begin writeln(0);halt;end;
  print(i);
  repeat
    inc(i);
    while a[i]=0 do inc(i);
    if i>n+1 then break;
    if a[i]>0 then write('+');
    print(i);
    until i>=n+1;
  writeln;
end.