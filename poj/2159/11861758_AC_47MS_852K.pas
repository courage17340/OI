var
  s,t:string;
  a,b:array[1..26] of longint;
function yes:boolean;
var
  i,j,p:longint;
begin
  if length(s)<>length(t) then exit(false);
  fillchar(a,sizeof(a),0);
  fillchar(b,sizeof(b),0);
  for i:=1 to length(s) do inc(a[ord(s[i])-64]);
  for i:=1 to length(s) do inc(b[ord(t[i])-64]);
  for i:=1 to 25 do
    for j:=i+1 to 26 do
      if a[i]>a[j] then
        begin
          p:=a[i];
          a[i]:=a[j];
          a[j]:=p;
        end;
  for i:=1 to 25 do
    for j:=i+1 to 26 do
      if b[i]>b[j] then
        begin
          p:=b[i];
          b[i]:=b[j];
          b[j]:=p;
        end;
  for i:=1 to 26 do if a[i]<>b[i] then exit(false);
  exit(true);
end;
begin
  readln(s);
  readln(t);
  if yes then writeln('YES') else writeln('NO');
end.