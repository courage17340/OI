var
  a:array[1..100] of longint;
  b:array[1..5] of longint;
  i,j,n,x,p:longint;
  ch:char;
procedure print;
begin
  writeln('No');readln;
  halt;
end;
begin
  readln(n);
  i:=0;
  j:=0;
  x:=0;
  for p:=1 to n do
    begin
      read(ch);
      case ch of
        'A':begin
              inc(x);inc(j);a[j]:=x;
            end;
        'B':begin
              if i=5 then print;
              inc(x);inc(i);b[i]:=x;
            end;
        'C':begin
              if i=0 then print;
              inc(j);a[j]:=b[i];dec(i);
            end;
      end;
    end;
  writeln('Yes');
  for i:=1 to j do writeln(a[i]);
end.