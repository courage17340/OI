var
  d:array[1..26] of char;
  f:array[1..1000] of longint;
  i,ans:longint;
  s,s1:ansistring;
function is(a,b:char):boolean;
var
  i,j:longint;
begin
  for i:=1 to 26 do if a=d[i] then break;
  for j:=1 to 26 do if b=d[j] then break;
  if i>=j then exit(true);
  exit(false);
end;
procedure work;
var
  i,j:longint;
begin
  ans:=0;
  fillchar(f,sizeof(f),0);
  for i:=1 to length(s1) do f[i]:=1;
  for i:=2 to length(s1) do
    for j:=1 to i-1 do
      if is(s1[i],s1[j]) and (f[i]<f[j]+1) then f[i]:=f[j]+1;
  for i:=1 to length(s1) do
    if ans<f[i] then ans:=f[i];
end;
begin
  for i:=1 to 26 do read(d[i]);readln;
  readln(s);
  s1:='';
  for i:=1 to length(s) do
    if s[i] in ['a'..'z']
      then s1:=s1+s[i]
      else
        begin
          work;
          s1:='';
          write(ans);
        end;
  work;write(ans);writeln;
end.