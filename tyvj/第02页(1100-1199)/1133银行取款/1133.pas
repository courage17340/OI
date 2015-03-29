var
  a:array[1..1000] of longint;
  ch:char;
  i,j,x:longint;
begin
  fillchar(a,sizeof(a),0);
  i:=1;j:=0;
  while not eof do
    begin
      read(ch);
      case ch of
        'O':if i>j
              then begin writeln('None');readln;end
              else
                begin
                  writeln(a[i]);
                  inc(i);readln;
                end;
        'I':begin
              readln(x);
              inc(j);
              a[j]:=x;
            end;
        end;
    end;
end.