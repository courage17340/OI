var
  n,i,j,ans:longint;
  a:array[1..200] of longint;
  v:array[1..200] of boolean;
  s:string;
function f(k:longint;s:string):longint;
var
  i:longint;
begin
  if copy(s,1,3)<>'go ' then exit(k+1);
  delete(s,1,3);
  while s[1]=' ' do delete(s,1,1);
  f:=0;
  for i:=1 to length(s) do
    if s[i] in ['0'..'9'] then
      f:=f*10+ord(s[i])-48
      else exit(k+1);
  if f>n then exit(k+1);
end;
begin
  readln(n);
  for i:=1 to n do
    begin
      readln(s);
      a[i]:=f(i,s);
      v[i]:=false;
    end;
  ans:=1;
  j:=1;
  v[1]:=true;
  while a[j]<=n do
    begin
      j:=a[j];
      if v[j] then
        begin
          ans:=-1;
          break;
        end;
      inc(ans);
      v[j]:=true;
    end;
  writeln(ans);
end.