var
  a:array['A'..'Z'] of char;
  st1,st2:string;
  i,j,n:longint;
procedure print;
begin writeln('Failed');halt;end;
begin
  fillchar(a,sizeof(a),' ');
  readln(st1);
  readln(st2);
  n:=length(st1);
  for i:=1 to n do
    begin
      if a[st1[i]]=' ' then a[st1[i]]:=st2[i]
        else if a[st1[i]]<>st2[i] then print;
    end;
  for i:=0 to 24 do
    for j:=i+1 to 25 do if a[chr(i+ord('A'))]=a[chr(j+ord('A'))] then print;
  readln(st1);
  st2:='';
  for i:=1 to length(st1) do
    if a[st1[i]]=' ' then print else st2:=st2+a[st1[i]];
  writeln(st2);
end.